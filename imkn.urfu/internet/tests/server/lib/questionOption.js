const pool = require('../db')

class QuestionOption {
  static async get({questionId}) {
    const db = await pool.connect()
    const {rows:questionOptions} = await db.query(`
      SELECT * FROM options
      WHERE question_id = $1`,
      [questionId]
    )
    db.release()

    return questionOptions
  }
}

module.exports = QuestionOption
