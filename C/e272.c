#include <stdio.h>
#define SWAP(x, y) (x)^=((y)^=((x)^=(y)))
#define MAX 94
#define BUFSIZ 1048576

unsigned long long F[MAX] = { 0, 1 };

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

inline char readUInt(unsigned int* dst)
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
    char buffer[22], * st = buffer + 20;
    *st = suffix, * (st + 1) = 0;
    do
    {
        *(--st) = src - ((div = src / 10) << 3) - (div << 1) + '0';
    } while (src = div);
    fputs(st, stdout);
}

inline int GCD(int n, int m)
{
    while (n)
    {
        m %= n;
        SWAP(m, n);
    }
    return m;
}

int main()
{
    int m, n;
    for (int i = 2; i < MAX; ++i)
        F[i] = F[i - 1] + F[i - 2];
    while (readUInt(&n), readUInt(&m))
        putULongLong(F[GCD(m, n)], '\n');
    return 0;
}