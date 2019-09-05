#include <stdio.h>
#define BUFSIZ 1048576

inline char readChar()
{
    static char buffer[BUFSIZ], * t0 = buffer + BUFSIZ, * end = buffer + BUFSIZ;
    if (t0 == end)
    {
        if (end < buffer + BUFSIZ)
            return EOF;
        end = (buffer + fread(buffer, 1, BUFSIZ, stdin));
        t0 = buffer;
    }
    return *t0++;
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

int main()
{
    unsigned int n, ans = 0, tmp;
    scanf(" %d", &n);
    while (--n)
    {
        readUInt(&tmp);
        ans ^= tmp;
    }
    printf("%d", ans);
    return 0;
}