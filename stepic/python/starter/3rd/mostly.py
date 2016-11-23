import re

amount = {};
def remember(word):
    global amount

    if word in amount.keys():
        amount[word] += 1
    else:
        amount[word] = 1

with open('dataset_3363_3.txt', 'r') as dataset:
    for line in dataset.readlines():
        for word in line.split():
            remember(word.lower())

mostly = 0
result = []
for word, count in amount.items():
    global result, mostly

    if count == mostly:
        result.append(word)
    elif count > mostly:
        result = [word]
        mostly = count

result.sort()
print (result, mostly)
