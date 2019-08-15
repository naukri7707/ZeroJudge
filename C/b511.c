#include <stdio.h>

const char strfmt[6][20] = { "" , "(%d)\n" , "(%d,%d)\n" , "(%d,%d,%d)\n" , "(%d,%d,%d,%d)\n"  , "(%d,%d,%d,%d,%d)\n" };
int n, m, max, coin[5], cont[5];

void dfs(int sum, int lv)
{
    for (int i = 0; sum < m; i++)
    {
        if (lv < max)
            dfs(sum, lv + 1);
        sum += coin[lv];
        cont[lv]++;
    }
    if (sum == m)
        printf(strfmt[n], cont[0], cont[1], cont[2], cont[3], cont[4]);
    cont[lv] = 0;
}

int main()
{
    while (scanf(" %d", &n) == 1)
    {
        for (int i = 0; i < n; i++)
            scanf(" %d", &coin[i]);
        scanf(" %d", &m);
        max = n - 1;
        dfs(0, 0);
    }
    return 0;
}