import sys

for fs in sys.stdin:
    out = ""
    for c in fs:
        out += chr(ord(c)-7)
    print(out)
