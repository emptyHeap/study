const router = require('koa-router')()
const category = require('../lib/category')

router.get('/', async (ctx) => {
  ctx.body = await category.get()
})

module.exports = router
