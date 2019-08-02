import sys

for fs in sys.stdin:
    a, b = map(int, fs.split())
    s = (a * 2 + b) % 3

    if s == 0:
        print('普通')
    elif s == 1:
        print('吉')
    else:
        print('大吉')
