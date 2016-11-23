import requests
import json
import sys

client_id = '6d46f46fd904c8efaeeb'
client_secret = '68c32c2106d3c85fad124096aa714bc9'

# инициируем запрос на получение токена
r = requests.post("https://api.artsy.net/api/tokens/xapp_token",
                  data={
                      "client_id": client_id,
                      "client_secret": client_secret
                  })

# разбираем ответ сервера
j = json.loads(r.text)

# достаем токен
token = j["token"]

# создаем заголовок, содержащий наш токен
headers = {"X-Xapp-Token" : token}
artists = []

for line in sys.stdin:
    if (line == '\n'):
        break
    # инициируем запрос с заголовком
    r = requests.get("https://api.artsy.net/api/artists/{}".format(line.rstrip()), headers=headers)
    r.encoding = 'utf-8'

    # разбираем ответ сервера
    j = json.loads(r.text)
    artists.append(j)

artists = sorted(artists, key = lambda x: (x['birthday'], x['sortable_name']))

for artist in artists:
    print(artist['sortable_name'])
