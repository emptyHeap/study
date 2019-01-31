import React from 'react'
import { BrowserRouter as Router, Route, Link } from "react-router-dom";

import Login from './login'
import Prepare from './prepare'
import Profile from './profile'
import PrepareQuestions from './prepare-questions'

console.log(PrepareQuestions)

class CoursesRouter extends React.Component {
  render() {
    return <Router>
      <div className="main-content">
        <header>
          <div className="main-menu">
            <div className="logo">
              <img src="img/cat-magic.png"></img>
            </div>
            <div className="list">
              <ul>
                <li>
                  <Link to="Prepare">Подготовка</Link>
                </li>
                <li>
                  <Link to="Profile">Профиль</Link>
                </li>
                <li>
                  <Link to="Login">Войти</Link>
                </li>
              </ul>
            </div>
          </div>
        </header>
        <Route path="/Prepare"               component={Prepare}></Route>
        <Route path="/PrepareQuestions\::id" component={PrepareQuestions}></Route>
        <Route path="/Profile"               component={Profile}></Route>
        <Route path="/Login"                 component={Login}></Route>
      </div>
    </Router>
  }
}

export default CoursesRouter
