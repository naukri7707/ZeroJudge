#include <stdio.h>
#include <memory.h>

int n, m, best;
char table[10][10];

void serch(int x, int y, int cont)
{
    if (cont > best)
        best = cont;
    int i;
    table[x][y] = 0;
    for (i = x + 1; i < n && !table[i][y]; ++i)
        ;
    while (++i < n)
    {
        if (table[i][y])
        {
            serch(i, y, cont + 1); break;
        }
    }
    for (i = x - 1; ~i && !table[i][y]; --i)
        ;
    while (--i >= 0)
    {
        if (table[i][y])
        {
            serch(i, y, cont + 1); break;
        }
    }
    for (i = y + 1; i < m && !table[x][i]; ++i)
        ;
    while (++i < m)
    {
        if (table[x][i])
        {
            serch(x, i, cont + 1); break;
        }
    }
    for (i = y - 1; ~i && !table[x][i]; --i)
        ;
    while (--i >= 0)
    {
        if (table[x][i])
        {
            serch(x, i, cont + 1); break;
        }
    }
    table[x][y] = 1;
}

int main()
{
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; ++i)
        memset(table[i], 1, m);
    serch(0, 0, 0);
    printf("%d\n", best);
    return 0;
}