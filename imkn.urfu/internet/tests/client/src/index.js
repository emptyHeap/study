import React from 'react'
import ReactDOM from 'react-dom'
import CoursesRouter from './routes'
import { Provider } from 'react-redux'
import rootReducer from './reducers'
import store from './store'

ReactDOM.render(
  <Provider store={store}>
    <CoursesRouter />
  </Provider>,
  document.getElementById('app')
)

//module.hot.accept()
