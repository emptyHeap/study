const url = require('url');
const request = require('request-promise');
const tough = require('tough-cookie');
const htmlParser = require('node-html-parser');
const { Client, Pool } = require('pg');
const db = new Pool();

const host = process.env.HOST;
const restrictions = false;

const types = {
  node: 'Olimp.UI.LearningCenter.Helpers.CatalogueTreeBuilder+NodeStub, Olimp.UI',
};

class Parser {
  constructor(host) {
    this.asyncs = 6;
    this.courses = [];
    this.themes = [];
    this.questions = [];
    this.host = host;
    this.jar = request.jar();
    this.request = request.defaults({
      jar: this.jar,
      //resolveWithFullResponse: true
    });
  }

  async parse() {
    await this._connect();
    await this._getCoursesList();
    await this._getThemes();
    await this._getQuestions();
    await this._getOptions();
    await this._getHelp();
    await this._finish();
  }

  /**
   * plain get host request, to get cookies
   */
  async _connect() {
    console.log('Connect and get cookies');

    const {request, host, jar} = this;

    await db.connect()
    const connectionResponse = await request.get(host, {
      resolveWithFullResponse: true,
      jar,
    });
    const [connCookie] = connectionResponse.caseless.dict['set-cookie'];
    this.jar.setCookie(connCookie, host);
    const prepareResponse = await request.get(`${host}/Prepare`, {
      resolveWithFullResponse: true,
      jar,
    });
    const [prepCookie] = prepareResponse.caseless.dict['set-cookie'];
    this.jar.setCookie(prepCookie, host);
    this.employeeId = prepCookie.match(/employeeId=(\d+)/)[1];

    console.log(`Connection successfull, employeeId=${this.employeeId}`);
  }

  async _login() {
    throw new Error('not implemented');
  }

  async _getCoursesList() {
    console.log('Get main page courses list');

    const {request, host, jar} = this;

    const rawCourseInfo = await request.post(`${host}/Prepare/StHome/GetCourse`, {
      qs: { profileId: 1},
      jar,
      json: true,
    });

    const parsedCourseInfo = await this._grubCourseInfo(rawCourseInfo.nodes[0], null);

    console.log('Main page courses list received');
  }

  async _grubCourseInfo(rawCoursesInfo, parent_id) {
    for (var courseInfo of rawCoursesInfo.nodes || []) {
      const {__type:type, name} = courseInfo;

      if (type === types.node) {
        const res = await db.query(
          'INSERT INTO categories(name, parent_id) VALUES ($1, $2) RETURNING id',
          [name, parent_id ? parent_id : null]);
        const [{id}] = res.rows;

        console.log(`Category added, looking for children (${id}): ${name}`);

        await this._grubCourseInfo(courseInfo, id);
      }
    }

    for (var course of rawCoursesInfo.materials || []) {
      const {__type:type, name, id:olimp_id, guid, code} = course;
      const res = await db.query(
        'INSERT INTO categories(name, parent_id) VALUES ($1, $2) RETURNING id',
        [name, parent_id ? parent_id : null]);
      const [{id}] = res.rows;

      this.courses.push({
        id, name, code, olimp_id, guid, type
      });

      console.log(`Course category added and sheduled (${id}): ${name}`);
    }
  }

  async _getThemes() {
    console.log('Get themes list');

    const {request, host, jar} = this;
    const themesPages = [];

    for (var course of this.courses) {
      const body = await request.get(`${host}/Prepare/Content/ShowThemes/${this.employeeId}/${course.olimp_id}`, {jar});
      const html = htmlParser.parse(body);
      const themeCells = html.querySelectorAll('td.theme-text');

      for (var themeCell of themeCells) {
        const description = themeCell.querySelector('div.theme-description').structuredText;

        const a = themeCell.querySelector('a');
        const {materialId, themeId} = url.parse(a.attributes.href, true).query;
        const name = a.structuredText;

        const {rows:[{id}]} = await db.query(
          'INSERT INTO categories(name, description, parent_id) VALUES ($1, $2, $3) RETURNING id',
          [name, description, course.id]
        );

        this.themes.push({
          id,
          materialId,
          themeId
        })

        console.log(`Category added, theme sheduled (${id}): ${name}`);
      }

      //return;
    }

    console.log('Themes list received');
  }

  async _getQuestions() {
    console.log('Get questions');

    const {themes} = this;
    const threads = [];

    for (var theme of themes) {
      threads.push(this._processThemeQuestions(theme));
    }

    await Promise.all(threads);

    console.log('\nQuestions received');
  }

  async _processThemeQuestions(theme) {
    const {jar, host, employeeId, questions} = this;
    const {materialId, themeId, id:category_id} = theme;

    let totalQuestions = 1;
    let currentPage = 1;

    while (questions.length < totalQuestions) {
      const questionsRequest = await request.post(`${host}/Prepare/Content/GetThemeQuestion`, {
        qs: { MaterialId:materialId, ThemeId:themeId, EmployeeId:employeeId },
        form: { pageSize: 50, currentPage},
        jar,
        json: true,
      });

      currentPage++;

      totalQuestions = questionsRequest.rowsCount;

      for (var question of questionsRequest.rows) {
        const {QuestionText: text, HasHelp: has_help, Number: number, Id: questionId} = question;
        const {rows: [{id}]} = await db.query(
          'INSERT INTO questions (text, category_id, number, has_help) VALUES ($1, $2, $3, $4) RETURNING id',
          [text, category_id, number, has_help],
        );

        questions.push({
          id,
          category_id,
          text,
          has_help,
          materialId,
          questionId,
          themeId,
          number
        });

        process.stdout.write('.');
      }
    }
  }

  async _processQuestions(callback) {
    const {questions, asyncs} = this;
    const stepLength = Math.round(questions.length / asyncs);
    const promises = [];
    let pointer = 0;
    let total = 0;

    while (pointer < questions.length) {
      const processingQuestions = questions.slice(pointer, pointer + stepLength);
      pointer += stepLength;

      promises.push(this[callback](processingQuestions));
    }

    await Promise.all(promises);
  }

  async _getOptions() {
    console.log('Get questions options');

    await this._processQuestions('_processOptions');

    console.log('\nQuestions options received');
  }

  //async _getOptions() {
  //  console.log('Get questions options');

  //  const {questions, asyncs} = this;
  //  const stepLength = Math.round(questions.length / asyncs);
  //  let pointer = 0;
  //  let total = 0;

  //  while (pointer < questions.length) {
  //    const processingQuestions = questions.slice(pointer, pointer + stepLength);
  //    pointer += stepLength;

  //    this._processOptions(processingQuestions);
  //  }

  //  console.log('Questions options received');
  //}

  async _processOptions(questions) {
    const {request, jar, host} = this;

    for (var question of questions) {
      const {materialId, questionId, id: question_id} = question;

      const questionPage = htmlParser.parse(await request.post(`${host}/Prepare/Content/ShowQuestion`, {
        qs: { materialId, questionId },
        jar
      }));

      const optionsRows = questionPage.querySelectorAll('#question-table tr');

      const options = [];
      for (var optionRow of optionsRows) {
        const {value: number} = optionRow.querySelector('input').attributes;
        const {structuredText: text} = optionRow.querySelector('td.answer-text');

        options.push({text, number});
        // Add image grubber
      }

      const firstInputType = questionPage.querySelector('#question-table input').attributes.type;

      if (firstInputType == 'radio') {
        // один вариант
        for (var option of options) {
          const stringResult = htmlParser.parse(
            await request.post(`${host}/Prepare/Content/CheckQuestion`, {
              jar,
              form: {questionId, materialId, answers: option.number},
            })
          )
            .querySelector('h1')
            .rawText;

          option.correct = stringResult
            .includes('неправильный ответ');
        }
      } else if (firstInputType === 'checkbox') {
        // несколько вариантов
        console.log('MULTIPLE', options, question);
      }

      for (var option of options) {
        const {text, correct, number} = option;

        await db.query(
          'INSERT INTO options (question_id, text, correct, number) VALUES ($1, $2, $3, $4)',
          [question_id, text, correct, number]
        );
        process.stdout.write('.');
      }
    }
  }

  async _getHelp() {
    console.log('Get questions help');

    await this._processQuestions('_processHelp');

    console.log('\nQuestions help received');
  }

  async _processHelp(questions) {
    const {request, jar} = this;

    for (var question of questions) {
      const {materialId, questionId, number, id} = question;

      const help = htmlParser.parse(await request.post(`${host}/Prepare/Content/ShowQHelp`, {
        form: {materialId, questionId, number},
        jar,
      })).structuredText;

      await db.query(
        'INSERT INTO questions_help (question_id, text) VALUES ($1, $2)',
        [id, help]
      );

      process.stdout.write('.');
    }
  }

  async _finish() {
    await db.end();
  }
}

let parser = new Parser(host);
parser.parse();
