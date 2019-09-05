#include <stdio.h>
#define BUFSIZ 1048576

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

inline char readLongLong(long long* dst)
{
    register char ch;
    while ((ch = readChar()) < '-')
        if (ch == EOF) return 0;
    if (ch == '-')
    {
        *dst = readChar() ^ '0';
        while ((ch = readChar()) >= '0')
            * dst = (*dst << 3) + (*dst << 1) + (ch ^ '0');
        *dst = ~*dst + 1;
    }
    else
    {
        *dst = ch ^ '0';
        while ((ch = readChar()) >= '0')
            * dst = (*dst << 3) + (*dst << 1) + (ch ^ '0');
    }
    return 1;
}

inline void putLongLong(register long long src, const char suffix)
{
    register unsigned long long div;
    char buffer[22], * st = buffer + 20;
    *st = suffix, * (st + 1) = 0;
    if (src < 0)
    {
        src = ~src + 1;
        *(--st) = src - ((div = src / 10) << 3) - (div << 1) + '0';
        while (src = div)
            * (--st) = src - ((div = src / 10) << 3) - (div << 1) + '0';
        *(--st) = '-';
    }
    else
    {
        do
        {
            *(--st) = src - ((div = src / 10) << 3) - (div << 1) + '0';
        } while (src = div);
    }
    fputs(st, stdout);
}

int main()
{
    register long long sum = 0;
    long long tmp;
    scanf("%*lld");
    while (readLongLong(&tmp))
        putLongLong((sum += tmp), ' ');
    return 0;
}