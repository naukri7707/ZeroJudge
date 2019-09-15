#include <stdio.h>
#define BUFSIZ 1048576
#define SWAP(x, y) (x)^=((y)^=((x)^=(y)))

inline char readChar()
{
    static char buffer[BUFSIZ], * now = buffer + BUFSIZ, * end = buffer + BUFSIZ;
    if (now == end)
    {
        if (end < buffer + BUFSIZ)
            return EOF;
        end = (buffer + fread(buffer, 1, BUFSIZ, stdin));
        now = buffer;
    }
    return *now++;
}

inline char readULongLong(unsigned long long* dst)
{
    register char ch;
    while ((ch = readChar()) < '0')
        if (ch == EOF) return 0;
    *dst = ch ^ '0';
    while ((ch = readChar()) >= '0')
        * dst = (*dst << 3) + (*dst << 1) + (ch ^ '0');
    return 1;
}

inline void putULongLong(register unsigned long long src, const char suffix)
{
    register unsigned long long div;
    char tmp[22], * st = tmp + 20;
    *st = suffix, * (st + 1) = 0;
    do
    {
        *(--st) = src - ((div = src / 10) << 3) - (div << 1) + '0';
    } while (src = div);
    fputs(st, stdout);
}

int main()
{
    unsigned long long f, t;
    while (readULongLong(&f), readULongLong(&t))
    {
        if (t < f) SWAP(t, f);
        while (f < t)
            t &= (t - 1);
        putULongLong(t, '\n');
    }
    return 0;
}