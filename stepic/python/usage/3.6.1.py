import sys
import requests
import json

for line in sys.stdin:
    params = {
            'json': 'true',
    }
    url = 'http://numbersapi.com/{}/math'.format(line.rstrip())
    r = requests.get(url, params=params)
    number = json.loads(r.text)
    if (number['found']):
        print('Interesting')
    else:
        print('Boring')
