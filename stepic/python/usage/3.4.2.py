import re, requests

file = requests.get(input())
#links = re.findall(r'<a\s+(:?\w+\s+)?href=[\'"](?!\.\.)(?!\?)(?:\w+://)?([^:/\'"]*)', file.text)
links = re.findall(r'<a\s+(:?.+\s+)?href=[\'"](?!\.\.)(?:\w+://)?([^:/\'"]*)', file.text)
print(links)
result = sorted(set([link[1] for link in links]))
print(result)
