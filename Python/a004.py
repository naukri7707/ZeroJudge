import sys

for fs in sys.stdin:
    y = int(fs)
    if (y % 400 == 0 or (y % 4 == 0 and y % 100 != 0)):
        print('閏年')
    else:
        print('平年')