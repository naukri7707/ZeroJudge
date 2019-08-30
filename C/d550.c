#include <stdio.h>
#include <stdlib.h>
#define BUFSIZ 1048576
#define ROW 10000
#define COL 200

int n, m, list[ROW][COL], * sort[ROW];

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

int cmp(const int** lhs, const int** rhs)
{
    for (int i = 0; i < m; i++)
    {
        if ((*lhs)[i] > (*rhs)[i])
            return 1;
        else if ((*lhs)[i] < (*rhs)[i])
            return -1;
    }
    return 0;
}

void putUInt(register int src, const char suffix)
{
    char buf[12], * bufTop = buf + 10;
    register int div;
    buf[10] = suffix, buf[11] = 0;
    do
    {
        *--bufTop = src - ((div = src / 10) << 3) - (div << 1) + '0';
    } while (src = div);
    fputs(bufTop, stdout);
}

int main()
{
    for (int i = 0; i < ROW; i++)
        sort[i] = list[i];
    while (scanf(" %d %d", &n, &m) == 2)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                readUInt(&list[i][j]);
        }
        qsort(sort, n, sizeof(int*), cmp);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                putUInt(sort[i][j], ' ');
            putchar('\n');
        }
    }
    return 0;
}