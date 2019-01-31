import React from 'react'
import QuestionsService from '../services/questions'

class PrepareQuestions extends React.Component {
  constructor(props) {
    super(props)
    this.state = {
      questions: [],
      lastPage: 0,
      totalPages: 1
    }
  }
  async componentDidMount() {
    const {id:categoryId} = this.props.match.params
    let {lastPage, totalPages} = this.state;

    while (lastPage < totalPages) {
      const {json: {
        rows: questions,
        pages
      }} = await QuestionsService.list({
        categoryId,
        page: lastPage,
        pages: 1
      })

      totalPages = pages
      lastPage++

      console.log(questions)

      this.setState({
        questions: [...this.state.questions, ...questions],
        lastPage,
        totalPages,
      })
    }
  }

  showQuestion(id) {

  }

  showHelp(id) {

  }

  render() {
    return <div className="prepare">
      <ul className="question-list">{
        this.state.questions.map(question => (<li
          className="question"
          key={question.id}>
          <div
            className="question__text"
            dangerouslySetInnerHTML={{__html:question.text}}
            onClick={() => this.showQuestion(question.id)}>
          </div>
        </li>))}
      </ul>
      <div className="question-block absolutly-center">
      </div>
    </div>
  }
}

export default PrepareQuestions
