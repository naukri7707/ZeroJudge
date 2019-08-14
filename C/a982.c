#include <stdio.h>
#define MAX 2147483647

int table[100][100];

int main()
{
    int n, end, now;
    char tmp, moving;
    while (scanf(" %d", &n) == 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf(" %c", &tmp);
                table[i][j] = tmp == '#' ? -1 : MAX;
            }
        }
        end = n - 2, now = 0, moving = table[1][1] = 1;
        while (table[end][end] == MAX && moving)
        {
            moving = 0, now++;
            for (int i = 1; i <= end; i++)
            {
                for (int j = 1; j <= end; j++)
                {
                    if (table[i][j] == now)
                    {
                        if (table[i][j + 1] > now) table[i][j + 1] = now + 1;
                        if (table[i][j - 1] > now) table[i][j - 1] = now + 1;
                        if (table[i + 1][j] > now) table[i + 1][j] = now + 1;
                        if (table[i - 1][j] > now) table[i - 1][j] = now + 1;
                        moving = 1;
                    }
                }
            }
        }
        if (moving)
            printf("%d\n", table[end][end]);
        else
            puts("No solution!");

    }
    return 0;
}