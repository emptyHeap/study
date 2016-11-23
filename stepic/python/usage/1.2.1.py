ids = set()
for object in objects:
	uniq.add(id(object))

print(len(ids))
