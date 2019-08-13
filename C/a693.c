#include <stdio.h>

int full[100010];

int main()
{
    int n, m, f, t;
    while (scanf(" %d %d", &n, &m) == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf(" %d", &full[i]);
            full[i] += full[i - 1];
        }
        for (int i = 1; i <= m; i++)
        {
            scanf(" %d %d", &f, &t);
            printf("%d\n", full[t] - full[f - 1]);
        }
    }
    return 0;
}