#include <stdio.h>

int member[100001], t;

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
    int n, g, m, t, tmp;
    while (readUInt(&n))
    {
        for (int i = 0; i < n; i++)
        {
            readUInt(&g), readUInt(&m);
            for (int j = 0; j < m; j++)
            {
                readUInt(&tmp);
                member[tmp] = g;
            }
        }
        readUInt(&t);
        printf("%d\n", member[t]);
    }
    return 0;
}