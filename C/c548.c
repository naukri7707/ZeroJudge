#include <stdio.h>
#define MAX 100010

int n, k, list[MAX], ans[MAX], aLen;

char dfs(int s, long long sum)
{
    if (!(sum % k) && sum)
        return 1;
    for (int i = s; i <= n; i++)
    {
        if (dfs(i + 1, sum + list[i]))
        {
            ans[aLen++] = i;
            return 1;
        }
    }
    return 0;
}

int main()
{
    while (scanf(" %d %d", &n, &k) == 2)
    {
        aLen = 0;
        for (int i = 1; i <= n; i++)
            scanf(" %d", &list[i]);
        if (dfs(1, 0))
        {
            printf("%d\n", aLen);
            for (int i = 0; i < aLen; i++)
                printf("%d ", ans[i]);
            putchar('\n');
        }
        else
        {
            puts("0");
        }
    }
    return 0;
}