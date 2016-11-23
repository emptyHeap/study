commands = int(input())

parents = {}

def inherited(posible_parent, child):
    global parents
    if posible_parent is child:
        return True
    elif parents[child] is None:
        return False
    elif posible_parent in parents[child]:
        return True
    else:
        for parent in parents[child]:
            if inherited(posible_parent, parent):
                return True
    return False

for i in range(commands):
    info = input().split(' : ')
    child = info[0]
    if len(info) == 2:
        parents[child] = info[1].split()
    else:
        parents[child] = None

commands = int(input())

for i in range(commands):
    parent, child = input().split()
    if inherited(parent, child):
        print('Yes')
    else:
        print('No')
