#include <stdio.h>

int sum[510][510];

int main()
{
    int n, m, sX, sY, eX, eY;
    while (scanf(" %d %d", &n, &m) == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                scanf(" %d", &sum[i][j]);
                sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d %d", &sX, &sY, &eX, &eY);
            printf("%d\n", sum[eX][eY] - sum[eX][sY - 1] - sum[sX - 1][eY] + sum[sX - 1][sY - 1]);
        }
    }
    return 0;
}