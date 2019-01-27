const {Pool} = require('pg')
const {
  db: {
    host,
    user,
    database,
    password,
    port,
    max,
    idleTimeoutMillis,
    connectionTimeoutMillis
  }
} = require('../config')

const pool = new Pool({
  host,
  user,
  database,
  password,
  port,
  max,
  idleTimeoutMillis,
  connectionTimeoutMillis,
})

module.exports = pool;
