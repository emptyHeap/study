const pool = require('../db')

class QuestionHelp {
  static async get({questionId}) {
    const db = await pool.connect()
    const {rows:help} = await db.query(`
      SELECT * from questions_help
      WHERE question_id = $1`,
      [questionId]
    )
    db.release()

    return help[0]
  }
}

module.exports = QuestionHelp
