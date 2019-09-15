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

long long gap(long long num1, long long num2)
{
    return num1 > num2 ? num1 - num2 : num2 - num1;
}

int main()
{
    long long dx, dy, cx, cy, da;
    while (readLongLong(&dx) & readLongLong(&dy) & readLongLong(&cx) & readLongLong(&cy) & readLongLong(&da))
    {
        puts(gap(dx, cx) + gap(dy, cy) > da ? "alive" : "die");
    }
    return 0;
}