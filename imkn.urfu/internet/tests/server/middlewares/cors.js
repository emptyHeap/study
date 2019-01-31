function addCorsHeaders(ctx) {
  ctx.set('Access-Control-Allow-Origin', ctx.req.headers.origin || '*')
  ctx.set('Access-Control-Allow-Methods', 'HEAD', 'POST, GET, OPTIONS, PUT, PATCH, DELETE')
  ctx.set('Access-Control-Allow-Headers', 'Content-Length, Content-Type, Content-Encoding, Content-Disposition, X-Requested-With, Transfer-Encoding, Server, Token')
  ctx.set('Content-Type', 'application/json')
  ctx.set('Access-Control-Allow-Credentials', true)
}

module.exports = async function (ctx, next) {
  addCorsHeaders(ctx)

  if (ctx.method === 'OPTIONS') {
    ctx.body = {}
  } else {
    try {
      await next()
    } catch(e) {
      console.log(e)
      ctx.status = e.status || 500
      ctx.body = e.message
      addCorsHeaders(ctx)
    }
  }
}
