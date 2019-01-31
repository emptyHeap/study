import React from 'react'
import CategoryNode from './category-node'
import category from '../services/categories'

class Categories extends React.Component {
  constructor(props) {
    super(props)

    this.state = {
      categories: this.props.categories || null
    }
  }

  componentWillReceiveProps(props) {
    this.setState(props)
  }

  render() {
    return <div className="categories-list">
      <h1>Выбор категории</h1>
      <div>
        {this.state.categories
          ? this.state.categories.map(category =>
            <CategoryNode
              selectCallback={this.props.selectCallback}
              key={category.id}
              {...category}
            />)
          : <div> Loading ... </div>}
      </div>
    </div>
  }
}

export default Categories
