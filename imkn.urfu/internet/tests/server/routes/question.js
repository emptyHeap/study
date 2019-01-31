const router = require('koa-router')()
const Question = require('../lib/question')
const QuestionOption = require('../lib/questionOption')
const QuestionHelp = require('../lib/questionHelp')
const {pageSize} = require('../lib/const')

router.get('/', async (ctx) => {
  const {page, pages, categoryId} = ctx.query
  const {rows, count} = await Question.list({
    limit: pages*pageSize,
    offset: page*pageSize,
    categoryId,
  })

  ctx.body = {
    rows,
    pages: Math.ceil(count/pageSize),
  }
})

router.get('/:id/help', async (ctx) => {
  const {id: questionId} = ctx.params
  const questionHelp = await QuestionHelp.get({questionId})

  ctx.body = questionHelp
})

router.get('/:id/options', async (ctx) => {
  const {id: questionId} = ctx.params
  const questionOptions = await QuestionOption.get({questionId})

  ctx.body = questionOptions
})

router.get('/:id/check', async (ctx) => {
  const {id} = ctx.params
  const {number} = ctx.query
  const sid = ctx.cookies.get('sid')
  const option = await Question.check({mode: 'prepare', number, id, sid})

  ctx.body = option
})

module.exports = router
