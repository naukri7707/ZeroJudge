import sys

_ = sys.stdin.readline()

for fs in sys.stdin:
    s = fs.split()
    n1, n2, n3, n4 = map(int, s)
    if(n1 - n2 == n3 - n4):
        print(s[0] + " " + s[1] + " " + s[2] +
              " " + s[3] + " " + str(n4 + n2 - n1))
    else:
        print(s[0] + " " + s[1] + " " + s[2] +
              " " + s[3] + " " + str(int(n4 * n2 / n1)))
