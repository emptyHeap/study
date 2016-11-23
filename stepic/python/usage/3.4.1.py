import requests as req
import re

firstlink = input()
secondlink = input()

p = r'<a\s+(?:[^>]*\s+)?href="([^"]*)"'
p = re.compile(p)

def getlinks(url):
    global p

    request = req.get(url)
    links = p.findall(request.text)
    return links

flinks = getlinks(firstlink)
for link in flinks:
    if secondlink in getlinks(link):
        print("Yes")
        raise SystemExit(0)

print("No")
