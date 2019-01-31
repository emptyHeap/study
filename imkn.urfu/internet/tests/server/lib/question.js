const pool = require('../db')
const sessionStorage = require('./session')

class Question {
  static async list({limit, offset, categoryId}) {
    const db = await pool.connect()
    const {rows:questions} = await db.query(`
      SELECT id, text, number, has_help
      FROM questions
      WHERE category_id = $3
      ORDER BY number
      LIMIT $1
      OFFSET $2`,
      [limit, offset, categoryId]
    )
    const {rows:[{count}]} = await db.query(`
      SELECT count(*)
      FROM questions
      WHERE category_id = $1`,
      [categoryId]
    )
    db.release()

    return {
      count,
      rows: questions
    }
  }

  static async check({id, mode, number, sid}) {
    const db = await pool.connect()
    const {rows} = await db.query(`
      SELECT correct
      FROM options
      WHERE question_id = $1 AND number = $2`,
      [id, number]
    )
    db.release()

    return rows[0]
  }
}

module.exports = Question
