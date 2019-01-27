const sessionStorage = require('../lib/session').storage
const crypto = require('crypto')
const pool = require('../db')

class Auth {
  static async login({email, password}) {
    const db = await pool.connect()
    const {rows} = await db.query(`
      SELECT id, name, email
      FROM users
      WHERE email = $1 AND password_hash = $2`,
    [email, password])
    db.release()

    if (rows.length !== 1) return false

    const sid = crypto.randomBytes(16).toString('hex')
    sessionStorage.set(sid, {email, password})
    return sid
  }

  static async logout({sid}) {
    return sessionStorage.delete(sid)
  }

  static async changePassword({email, sid, newPassword}) {
    if (sid) {
      const user = sessionStorage.get(sid)
    } else if (name) {
      // start restore process
    }
  }

  static async register({email, password}) {
    const db = await pool.connect()
    const {rows} = await db.query(`
      SELECT id
      FROM users
      WHERE email = $1`,
      [email]
    )

    if (rows.length > 0) {
      db.release()
      return false
    }

    const {rows:newUserRows} = await db.query(`
      INSERT INTO users (email, password_hash)
      VALUES ($1, $2)
      RETURNING *`,
      [email, password])
    db.release()

    console.log(password)

    return Auth.login({email, password})
  }

  static async sessionInfo({sid}) {
    return sessionStorage.get(sid)
  }
}

module.exports = Auth
