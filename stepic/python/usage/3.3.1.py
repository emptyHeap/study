import sys
import itertools as it
import re
pattern = r"cat"

for line in sys.stdin:
    line = line.rstrip()
    if len(list(it.islice(re.finditer(pattern, line), None, 2))) > 1:
        print(line)
