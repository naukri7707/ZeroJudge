import sys

for fs in sys.stdin:
    print(eval(fs.replace("/", "//")))
