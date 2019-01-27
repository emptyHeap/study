const pool = require('../db')

class Category {
  static async get() {
    const db = await pool.connect()
    const {rows:categories} = await db.query(`
      SELECT id, name, description, parent_id
      FROM categories`)
    db.release()

    const categoriesMap = new Map()
    const result = []

    for (var category of categories) {
      category.children = []
      categoriesMap.set(category.id, category)
      if (!category.parent_id) result.push(category)
    }

    for (var category of categories) {
      const {parent_id} = category

      if (parent_id) {
        categoriesMap.get(parent_id).children.push(category)
      }
    }

    return result
  }
}

module.exports = Category
