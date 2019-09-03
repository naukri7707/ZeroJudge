#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 1048576
#define MAX 100010

int list[MAX];

inline char readChar()
{
    static char buffer[BUFSIZE], * now = buffer + BUFSIZE, * end = buffer + BUFSIZE;
    if (now == end)
    {
        if (end < buffer + BUFSIZE)
            return EOF;
        end = (buffer + fread(buffer, 1, BUFSIZE, stdin));
        now = buffer;
    }
    return *now++;
}

inline char readInt(int* dst)
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

int cmp(const void* lhs, const void* rhs)
{
    return *(int*)lhs - *(int*)rhs;
}

int main()
{
    int n, m, key, * idx;
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++)
        readInt(&list[i]);
    while (m--)
    {
        readInt(&key);
        if (idx = (int*)bsearch(&key, list, n, sizeof(int), cmp))
           putUInt(idx - list + 1, '\n');
        else
            puts("0");
    }
    return 0;
}