#include <stdio.h>
#include <stdlib.h>

int n, m, next, list[50], output[50];
char noAns;

int cmp(const int* lhs, const int* rhs)
{
    return *lhs - *rhs;
}

void dfs(int sum, int start, int depth)
{
    for (int i = start; i < n; i++)
    {
        next = sum + list[i];
        if (next >= m)
        {
            if (next == m)
            {
                for (int j = 0; j < depth; j++)
                    printf("%d ", output[j]);
                printf("%d\n", list[i]);
                noAns = 0;
            }
            if (list[i] < list[i + 1])
                return;
        }
        output[depth] = list[i];
        if (next + list[i] <= m)
            dfs(next, i + 1, depth + 1);
    }
}

int main()
{
    while (scanf(" %d %d", &n, &m) == 2)
    {
        noAns = 1;
        for (int i = 0; i < n; i++)
            scanf(" %d", &list[i]);
        qsort(list, n, sizeof(int), cmp);
        dfs(0, 0, 0);
        if (noAns)
            puts("-1");
    }
    return 0;
}