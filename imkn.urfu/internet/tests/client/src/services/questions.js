import LocalService from '../lib/local-service'

class QuestionsService extends LocalService {
  list({categoryId, page, pages}) {
    return this.get('', {
      query: {
        categoryId,
        page,
        pages,
      }
    })
  }
}

export default new QuestionsService('question')
