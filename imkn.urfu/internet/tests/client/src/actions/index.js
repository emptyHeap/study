import actionTypes from './actionTypes'

console.log(actionTypes)

const { PAGE_CHANGE } = actionTypes

export const changePage = page => ({
  type: PAGE_CHANGE,
  page
})

/* example structure
{
  page,
  history,
  exam,
  modal: {
    type,
    data,
  }
}
*/
