#include <stdio.h>
#include <memory.h>

int list[10000];

int main()
{
    int n, m, f, t, count;
    while (scanf(" %d %d", &n, &m) == 2)
    {
        memset(list + 1, 0, sizeof(int) * n);
        for (int i = 0; i < m; i++)
        {
            scanf(" %d %d", &f, &t);
            list[f]++, list[t]++;
        }
        count = 0;
        for (int i = 1; i <= n; i++)
        {
            if (list[i] & 1)
            {
                count++;
                if (count > 2)
                    break;
            }
        }
        puts(count < 3 ? "YES" : "NO");
    }
    return 0;
}