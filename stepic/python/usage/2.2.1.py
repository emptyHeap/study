import datetime

date = datetime.datetime(*[int(i) for i in input().split()])
dif = datetime.timedelta(days = int(input()))
newdate = (date + dif)
print(newdate.year, newdate.month, newdate.day)
