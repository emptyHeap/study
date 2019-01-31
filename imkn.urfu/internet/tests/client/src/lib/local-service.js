import consts from '../consts.js'
import path from 'path'

class LocalService {
  constructor(prefix) {
    const {backend: {host, port, protocol}} = consts
    this.url = new URL(`${protocol}://${host}:${port}/${prefix}`)
    console.log(this.url)
  }
  async request(method, suffix = '', options = {}) {
    const {query = {}, body} = options
    const url = new URL(path.join(this.url.pathname,suffix), this.url)
    for (const [key, value] of Object.entries(query)) {
      url.searchParams.set(key, value)
    }

    try {
      const result = await fetch(url, {
        method,
        ...(body ? {body: JSON.stringify(body)} : {}),
        mode: 'cors',
        headers: {
          'Content-Type': 'application/json'
        },
      })

      const {ok, status} = result

      return {
        ok,
        status,
        json: result.ok ? await result.json() : null
      }
    } catch(e) {
      // log error or show to user popup
      return false;
    }
  }

  get(...args) {
    return this.request('GET', ...args)
  }

  post(...args) {
    return this.request('POST', ...args)
  }

  put(...args) {
    return this.request('PUT', ...args)
  }

  patch(...args) {
    return this.request('PATCH', ...args)
  }

  delete(...args) {
    return this.request('DELETE', ...args)
  }

  //options(...args) {
  //  this.request('OPTIONS', ...args)
  //}
}

export default LocalService
