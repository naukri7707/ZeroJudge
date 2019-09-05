#include <stdio.h>
#define BUFSIZ 8192

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

int main()
{
    unsigned int t0, t1 = 0, t2 = 0, t3 = 0;
    scanf(" %*d");
    while (readUInt(&t0))
    {
        t3 = t2 & t0;
        t2 &= ~t3;
        t0 &= ~t3;
        t2 ^= t1 & t0;
        t1 ^= t0;
    }
    printf("%d", t1);
    return 0;
}