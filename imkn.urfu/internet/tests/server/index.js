const Koa = require('koa')
const logger = require('koa-logger')
const koaBody = require('koa-body')

const cors = require('./middlewares/cors')
const router = require('./routes')
const config = require('./config')

const app = new Koa()

app.use(logger())
app.use(cors)
app.use(koaBody())
app.use(router.routes())

const {port} = config

app.listen(port)
