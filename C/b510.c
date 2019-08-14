#include <stdio.h>

int max, count, table[11][11];

void dfs(int i, int m, int n)
{
    if (i == max)
    {
        count++;
        return;
    }
    for (int j = 0; j < max; j++)
    {
        if (table[i][j])
            continue;
        for (int k = i + 1; k < max; k++)
            table[k][j]++;
        if (m)
        {
            for (int k = i - 1, l = j - 1; k >= 0 && l >= 0; k--, l--)
                if (table[k][l] == -1) goto end;
            for (int k = i - 1, l = j + 1; k >= 0 && l < max; k--, l++)
                if (table[k][l] == -1) goto end;
            for (int k = i + 1, l = j - 1; k < max && l >= 0; k++, l--)
                table[k][l]++;
            for (int k = i + 1, l = j + 1; k < max && l < max; k++, l++)
                table[k][l]++;
            dfs(i + 1, m - 1, n);
            for (int k = i + 1, l = j - 1; k < max && l >= 0; k++, l--)
                table[k][l]--;
            for (int k = i + 1, l = j + 1; k < max && l < max; k++, l++)
                table[k][l]--;
        end:;
        }
        if (n)
            table[i][j] = -1, dfs(i + 1, m, n - 1), table[i][j] = 0;
        for (int k = i + 1; k < max; k++)
            table[k][j]--;
    }
}

int main()
{
    int m, n;
    while (scanf(" %d %d", &m, &n) == 2)
    {
        max = m + n, count = 0;
        dfs(0, m, n);
        printf("%d\n", count);
    }
    return 0;
}