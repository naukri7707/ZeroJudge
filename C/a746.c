#include <stdio.h>

char table[510][510];

inline void setGate(int n)
{
    for (int i = n; i; i--)
    {
        for (int j = n; j; j--)
            table[i][j] = ' ';
        table[i][0] = table[i][n + 1] = '|', table[i][n + 2] = '\0';
    }
    for (int i = n + 1; i >= 0; i--)
        table[0][i] = table[n + 1][i] = '-';
    table[0][n + 2] = table[n + 1][n + 2] = '\0';
}

int main()
{
    int n, m, sX, sY, eX, eY;
    while (scanf("%d %d", &n, &m) == 2)
    {
        setGate(n);
        scanf(" %d %d", &sX, &sY);
        table[sX][sY] = '*';
        while (--m)
        {
            scanf(" %d %d", &eX, &eY);
            if (sX == eX)
            {
                if (sY < eY)
                    while (++sY < eY) table[sX][sY] = '*';
                else
                    while (--sY > eY) table[sX][sY] = '*';
            }
            else
            {
                if (sX < eX)
                    while (++sX < eX) table[sX][sY] = '*';
                else
                    while (--sX > eX) table[sX][sY] = '*';
            }
            table[sX][sY] = '*';
        }
        for (int i = 0; i <= n + 1; i++)
            puts(table[i]);
    }
    return 0;
}