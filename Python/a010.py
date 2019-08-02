import sys

for fs in sys.stdin:
    num = int(fs.strip('\n'))
    out = ''
    i = 2
    while i <= num:
        count = 0
        while(num % i == 0):
            count += 1
            num /= i
        if count:
            if count == 1:
                out += str(i) + " * "
            else:
                out += str(i) + " ^ " + str(count) + " * "
        i += 1
    print(out[:-3])
