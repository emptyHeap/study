import sys
import itertools as it
import re
pattern = r"\b(.*)\B\1\b"

for line in sys.stdin:
    line = line.rstrip()
    if re.search(pattern, line):
        print(line)
