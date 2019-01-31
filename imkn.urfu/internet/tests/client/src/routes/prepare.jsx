import React from 'react'
import { changePage } from '../actions'
import Categories from '../components/categories'
import { connect } from 'react-redux'
import store from '../store'
import CategoriesService from '../services/categories'

class Prepare extends React.Component {
  constructor(props) {
    super(props)
    this.state = {
      categories: []
    }
  }
  async componentDidMount() {
    const {json:categories} = await CategoriesService.get()
    this.setState({categories})
    console.log(this.state.categories)
  }
  courseSelected(id) {
    console.log('course id: ', id)
    this.props.courseSelected(id)
    // make request
  }
  render() {
    return <Categories
      selectCallback={(id) => {this.props.courseSelected(id)}}
      categories={this.state.categories}
    />
  }
}

const mapStateToProps = state => {
  console.log('STATE CHANGED', state)
  return {}
}

const mapDispatchToProps = (dispatch, props) => ({
  courseSelected: (id) => {
    dispatch(changePage(`PrepareQuestions:${id}`))
    props.history.push(`PrepareQuestions:${id}`)
  }
})

export default connect(
  mapStateToProps,
  mapDispatchToProps
)(Prepare)
