import json
import sys

desc = json.loads(sys.stdin.readline())

class statman:
    children = {}
    def init(classes):
        for jclass in classes:
            statman.children[jclass['name']] = set()

    def count(jclass):
        for parent in jclass['parents']:
            statman.children[parent].add(jclass['name'])
        for child in statman.children[jclass['name']].copy():
            statman.children_count(child, jclass['name'])

    def children_count(parent, superparent):
        for child in statman.children[parent]:
            statman.children[superparent].add(child)
            statman.children_count(child, superparent)
            


statman.init(desc)
for jclass in desc:
    statman.count(jclass)

for jclass in desc:
    for child in statman.children[jclass['name']].copy():
        statman.children_count(child, jclass['name'])

for jclass, children in sorted(statman.children.items()):
    print("{} : {}".format(jclass, len(children)+1))
