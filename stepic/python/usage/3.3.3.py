import sys
import itertools as it
import re
pattern = r"z.{3}z"

for line in sys.stdin:
    line = line.rstrip()
    if re.search(pattern, line):
        print(line)
