import React from 'react'
import { connect } from 'react-redux'
import services from '../services'
import { changePage } from '../actions'
const {auth} = services

class Login extends React.Component {
  constructor(props) {
    super(props)

    this.state = {
      email: '',
      password: '',
      correct: undefined,
    }
  }
  async login() {
    const {email, password} = this.state
    const response = await auth.login(email, password)
    console.log(response)
    const {ok, status, message} = response
    if (!ok) {
      this.setState({correct: false})
    } else {
      this.setState({correct: true})
      this.props.loggedIn()
    }
  }
  render() {
    return <div className={
        this.state.correct === true
        ? 'success' :
        this.state.correct === false
        ? 'failed'
        : ''
      } id="login-form">
      <div id="email">
        <label htmlFor="email-input">email</label>
        <input
          onChange={event => this.setState({email: event.target.value})}
          id="email-input" type="text"></input>
      </div>
      <div id="password">
        <label htmlFor="password">password</label>
        <input
          onChange={event => this.setState({password: event.target.value})}
          type="password"></input>
      </div>
      <button
        onClick={event => this.login()}
        type="button">Войти</button>
    </div>
  }
}

const mapStateToProps = state => {
  console.log('MAP STATE', state)
  return {}
}

const mapDispatchToProps = (dispatch, props) => ({
  loggedIn: () => {
    dispatch(changePage('Prepare'))
    props.history.push('Prepare')
  }
})

export default connect(
  mapStateToProps,
  mapDispatchToProps,
)(Login)
