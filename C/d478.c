#include <stdio.h>
#define BUFSIZE 1048576
#define MAX 10010

unsigned int lhs[MAX], rhs[MAX];

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
    int n, m, l, r, count;
    scanf(" %d %d", &n, &m);
    while (n--)
    {
        count = l = r = 0;
        for (int i = 0; i < m; i++)
            readUInt(&lhs[i]);
        for (int i = 0; i < m; i++)
            readUInt(&rhs[i]);
        for (;;)
        {
            if (lhs[l] < rhs[r])
            {
                if (++l == m) break;
            }
            else if (rhs[r] < lhs[l])
            {
                if (++r == m) break;
            }
            else
            {
                count++;
                if (++l == m) break;
                if (++r == m) break;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}