#include <stdio.h>
#include <stdlib.h>

int n, m, list[1000], output[1000];

int cmp(const int* lhs, const int* rhs)
{
    return *lhs - *rhs;
}

void dfs(int lv, int st)
{
    if (lv == m)
    {
        for (int i = 0; i < m; i++)
            printf("%d ", output[i]);
        putchar('\n');
        return;
    }
    for (int i = st; i < n; i++)
    {
        output[lv] = list[i];
        dfs(lv + 1, i + 1);
    }
}

int main()
{
    while (scanf(" %d", &n) == 1 && n)
    {
        for (int i = 0; i < n; i++)
            scanf(" %d", &list[i]);
        qsort(list, n, sizeof(int), cmp);
        scanf(" %d", &m);
        dfs(0, 0);
    }
    return 0;
}