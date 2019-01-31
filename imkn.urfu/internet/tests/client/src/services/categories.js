import LocalService from '../lib/local-service'

class CategoriesService extends LocalService {
  get() {
    return super.get('/')
  }
}

export default new CategoriesService('category')
