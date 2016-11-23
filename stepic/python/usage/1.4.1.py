from collections import defaultdict

total_commands = int(input())

parents = {'global':None}
variables = defaultdict(list)
variables['global'] = []

def create(namespace, parent):
    global parents
    parents[namespace] = parent

def add(namespace, varname):
    global variables
    variables[namespace].append(varname)

def get(namespace, varname):
    global parents, variables
    while namespace != None:
        if varname in variables[namespace]:
            break
        else:
            namespace = parents[namespace]
    print(namespace)

commands = {
        'create': create,
        'add': add,
        'get': get
        }

for i in range(total_commands):
    command, a, b = (input().split())
    commands[command](a, b)
