string = input()
sub = input()

count = 0
start = 0
while start < len(string):
    start = string.find(sub, start) + 1
    if (start == 0):
        break
    else:
        count += 1;

print(count)
