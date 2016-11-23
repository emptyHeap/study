import requests

prefix = 'https://stepic.org/media/attachments/course67/3.6.3/'
first_word = '213837.txt'
content = ''

while first_word != 'We':
    r = requests.get(prefix + first_word)
    content = r.text
    first_word = content.split()[0]
    print(prefix + first_word)

print(content)
