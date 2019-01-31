import React from 'react'

class CategoryNode extends React.Component {
  constructor(props) {
    super(props)
  }

  render() {
    return (<div className="category-node">
      <a onClick={(event) => {
          this.props.selectCallback(this.props.id, 'prepare')
        }}><h3>{this.props.name}</h3></a>

      <div className="category-node__description">
        {this.props.description}
      </div>

      <div className="category-node__children">
      { this.props.children && this.props.children.length
        ? this.props.children.map((childNode) => (
            <CategoryNode
              selectCallback={this.props.selectCallback}
              key={childNode.id}
              {...childNode} />
          ))
        : 'i am leaf'
      }
      </div>
    </div>)
  }
}

export default CategoryNode
