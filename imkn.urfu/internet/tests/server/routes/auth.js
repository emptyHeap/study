const router = require('koa-router')()
const {
  login,
  logout,
  changePassword,
  register,
  sessionInfo
} = require('../lib/auth')

router.post('/login', async (ctx) => {
  const {email, password} = ctx.request.body
  const sid = await login({email, password})

  if (!sid) return ctx.throw(401, 'wrong credentials')

  ctx.cookies.set('sid', sid)
  ctx.body = {}
})

router.post('/logout', async (ctx) => {
  const {sid} = ctx.request.body
  ctx.body = await logout({sid})

  ctx.body = {}
})

router.post('/change-password', async (ctx) => {
  const {password} = ctx.request.body
  ctx.body = await changePassword({password})

  ctx.body = {}
})

router.post('/register', async (ctx) => {
  console.log(ctx.request);
  const {email, password} = ctx.request.body
  const sid = await register({email, password})

  if (!sid) return ctx.throw(409, 'email is already used')

  ctx.cookies.set('sid', sid)
  ctx.body = {}
})

router.get('/session', async (ctx) => {
  const {email, password} = ctx.request.body
  const sid = ctx.cookies.get('sid')

  ctx.body = await sessionInfo({sid})
})

module.exports = router;
