import sys

for fs in sys.stdin:
    a, b, c = map(int, fs.split())
    s = (b * b) - (4 * a * c)
    if(s < 0):
        print("No real root")
    else:
        sr = s ** 0.5
        x1 = int((-b + sr) / (2 * a))
        x2 = int((-b - sr) / (2 * a))

        if(sr):
            print("Two different roots x1=" + str(x1) +" , x2=" + str(x2))
        else:
            print("Two same roots x=" + str(x1))

