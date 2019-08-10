import sys

eng = [10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20, 21,
       22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 30, 31, 33]

for fs in sys.stdin:
    s = fs[:-1]
    sum = eng[ord(s[0])-ord('A')]
    sum = sum // 10 + (sum % 10) * 9
    num = list(map(int, s[1:]))
    mult = 8
    for n in num[:-2]:
        sum += n * mult
        mult -= 1
    sum += num[-2] + num[-1]
    print("real" if not(sum % 10) else "fake")
