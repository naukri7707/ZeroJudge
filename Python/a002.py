import sys

for s in sys.stdin:
    x, y = map(int, s.split())
    print(x+y)
