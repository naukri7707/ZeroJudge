import sys

while 1:
    try:
        row, col = map(int, sys.stdin.readline().split())
    except:
        break
    table = [input().split() for r in range(row)]
    out = ''
    for c in range(col):
        for r in range(row):
            out += table[r][c] + ' '
        out = out[:-1] + '\n'
    print(out)
