import sys

table = {"M": 1000, "CM": 900, "D": 500, "CD": 400, "C": 100, "XC": 90,
         "L": 50, "XL": 40, "X": 10, "IX": 9, "V": 5, "IV": 4, "I": 1}


def toInt(rome):
    res = 0
    prev = 9999
    i = 0
    while i < len(rome):
        if table[rome[i]] > prev:
            res += table[rome[i]] - (prev << 1)
        else:
            res += table[rome[i]]
        prev = table[rome[i]]
        i += 1
    return res


for fs in sys.stdin:
    r1 = fs.split()[0]
    if r1[0] == '#':
        break
    r2 = fs.split()[1]
    gap = abs(toInt(r1) - toInt(r2))
    if(gap == 0):
        print("ZERO")
    else:
        out = ""
        for k, v in table.items():
            while gap >= v:
                out += k
                gap -= v
        print(out)
