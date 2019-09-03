#include <stdio.h>

int main()
{
    int n, now, ans, gap;
    while (scanf(" %d", &n) == 1)
    {
        now = gap = 1, ans = 0;
        for (int i = 0; i < 50; i++)
            ans += now, now += gap, gap += n;
        printf("%d\n", ans);
    }
    return 0;
}