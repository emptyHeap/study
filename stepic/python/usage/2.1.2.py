class Class():
    instance = {}
    def __init__(self, name, parents = None):
        self.name = name
        Class.instance[name] = self
        self.parents = []
        if parents != None:
            self.parents.extend(parents)

    def child_of(self, estimate_parent):
        if self.parents == None:
            return False
        if estimate_parent in self.parents:
            return True
        for parent in self.parents:
            if Class.instance[parent].child_of(estimate_parent):
                return True
        return False

setup_steps = int(input())
for i in range(setup_steps):
    info = input().split(' : ')
    
    child = info[0]
    if len(info) > 1:
        Class(child, parents = info[1].split())
    else:
        Class(child)
    
exceptions = int(input())
handlers = [input()]
for i in range(exceptions-1):
    className = input()
    necessary = True
    for handler in handlers:
        if Class.instance[className].child_of(handler):
            necessary = False
            break
    if necessary:
        handlers.append(className)
    else:
        print(className)
    
