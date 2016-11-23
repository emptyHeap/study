import csv
import re

class statistics:
    crimes = dict() 
    def add(p_type):
        if p_type not in statistics.crimes:
            statistics.crimes[p_type] = 1
        else:
            statistics.crimes[p_type] += 1


with open(input()) as f:
    rows = csv.reader(f)
    headers = next(rows)
    date = headers.index("Date")
    p_type = headers.index("Primary Type")
    for row in rows:
        if re.match(r'[0-9]{2}/[0-9]{2}/2015', row[date]):
            statistics.add(row[p_type])

print(statistics.crimes)
