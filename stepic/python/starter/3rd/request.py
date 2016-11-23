import requests

url = 'https://stepic.org/media/attachments/course67/3.6.2/580.txt'
r = requests.get(url)
print(r.text)
print(len(r.text.splitlines()))
