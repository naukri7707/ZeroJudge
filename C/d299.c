#include <stdio.h>

int ans[10], isUse[10];

char dfs(int now, int step)
{
    int i, j;

    if (step == 10)
    {
        if (ans[1] * 10000 + ans[4] * 1000 + ans[5] * 100 + ans[7] * 10 + ans[9]
            + 2 * (ans[7] * 100 + ans[0] * 10 + ans[3])
            == ans[6] * 10000 + ans[2] * 1000 + ans[8] * 100 + ans[7] * 10 + ans[9])
        {
            printf("%d%d%d%d%d + %d%d%d + %d%d%d = %d%d%d%d%d\n",
                ans[1], ans[4], ans[5], ans[7], ans[9],
                ans[7], ans[0], ans[3],
                ans[7], ans[0], ans[3], ans[6], ans[2], ans[8], ans[7], ans[9]);
            return 1;
        }
        return 0;
    }
    for (i = 0; i < 10; i++)
    {
        if (isUse[i]) continue;
        ans[step] = i;
        isUse[i] = 1;
        if (dfs(i, step + 1))
            return 1;
        isUse[i] = 0;
    }
    return 0;
}

int main()
{
    dfs(0, 0);
    return 0;
}