#include <stdio.h>
#include <stdlib.h>
#define BUFSIZ 1048576

int list[100010];

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

inline void putUInt(register unsigned int src, const char suffix)
{
    register unsigned int div;
    char buffer[12], * st = buffer + 10;
    *st = suffix, * (st + 1) = 0;
    do
    {
        *(--st) = src - ((div = src / 10) << 3) - (div << 1) + '0';
    } while (src = div);
    fputs(st, stdout);
}


int cmp(const int* lhs, const int* rhs)
{
    return (*rhs) - (*lhs);
}

int main()
{
    int n;
    while (readUInt(&n))
    {
        for (int i = 0; i < n; i++)
            readUInt(&list[i]);
        qsort(list, n, sizeof(int), cmp);
        for (int i = n - 1; i; i--)
            putUInt(list[i], ' ');
        putUInt(list[0], '\n');
    }
    return 0;
}