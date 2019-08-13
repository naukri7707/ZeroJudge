#include <stdio.h>

int table[100][100];

int main()
{
    int kase, n, m;
    scanf(" %d", &kase);
    while (kase--)
    {
        scanf(" %d %d", &n, &m);
        int now = 1, end = n * n, sr = 0, sc = -1, er = n - 1, ec = n - 1, i, j;
        while (now <= end)
        {
            for (j = ++sc; j <= ec; j++)
                table[sr][j] = now++;
            for (i = ++sr; i <= er; i++)
                table[i][ec] = now++;
            for (j = --ec; j >= sc; j--)
                table[er][j] = now++;
            for (i = --er; i >= sr; i--)
                table[i][sc] = now++;
        }
        if (m == 1)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    printf("%5d", table[i][j]);
                putchar('\n');
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    printf("%5d", table[j][i]);
                putchar('\n');
            }
        }
    }
    return 0;
}