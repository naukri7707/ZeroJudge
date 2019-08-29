#include <stdio.h>

int n;
char ans[16];

void dfs(int lv)
{
    if (lv == n)
    {
        puts(ans);
        return;
    }
    ans[lv] = '0';
    dfs(lv + 1);
    ans[lv] = '1';
    dfs(lv + 1);
}

int main()
{
    while (scanf(" %d", &n) == 1)
    {
        ans[n] = 0;
        dfs(0);
    }
    return 0;
}