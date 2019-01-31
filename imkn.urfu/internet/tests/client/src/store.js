import { createStore } from 'redux'
import rootReducer from './reducers'
import { changePage } from './actions'

const store = createStore(rootReducer)

const unsubscribe = store.subscribe(() => {
  console.log(store.getState())
})

export default store
