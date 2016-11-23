import re

def decompress(string):
    result = ''
    for m in re.finditer('([a-zA-Z]+)(\d+)', string):
        result += m.group(1)*int(m.group(2))
    return result


with open('dataset_3363_2.txt', 'r') as dataset:
    with open('result.txt', 'w') as result:
        for line in dataset.readlines():
            result.write(decompress(line))
