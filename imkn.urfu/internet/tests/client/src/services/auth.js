import LocalService from '../lib/local-service'

console.log(LocalService)
const test = new LocalService('');
console.log(test)

class AuthService extends LocalService {
  constructor(...args) {
    super(...args)
  };

  login(email, password) {
    return this.post('login', {body:{email, password}})
  }

  logout() {
    return this.post('logout', {})
  }
}

export default new AuthService('auth')
