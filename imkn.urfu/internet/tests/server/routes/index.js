const router = require('koa-router')()

const auth= require('./auth')
const category= require('./category')
const question= require('./question')

router.use('/auth', auth.routes())
router.use('/category', category.routes())
router.use('/question', question.routes())

module.exports = router;
