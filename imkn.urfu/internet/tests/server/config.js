module.exports = {
  ...process.env,
  port: 3000,
  db: {
    host: 'localhost',
    user: 'ts_admin',
    database: 'test_system',
    password: 'qweqwe',
    port: 5433,
    max: 20,
    idleTimeoutMillis: 60000,
    connectionTimeoutMillis: 2000,
  },
}
