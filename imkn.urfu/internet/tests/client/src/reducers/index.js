import { combineReducers } from 'redux'
import actionTypes from '../actions/actionTypes'

const { PAGE_CHANGE } = actionTypes

function page(state = '', action) {
  switch(action.type) {
    case PAGE_CHANGE:
      return action.page
    default:
      return state
  }
}

export default combineReducers({
  page,
})
