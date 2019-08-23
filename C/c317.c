#include <stdio.h>

int main()
{
    int n, target, coin1, coin2, i, sum, count;
    while (scanf(" %d", &n) == 1)
    {
        while (n--)
        {
            scanf(" %d %d %d", &target, &coin1, &coin2);
            i = target / coin1, count = -1;
            sum = coin1 * (i + 1);
            for (; i >= 0; i--)
            {
                sum -= coin1;
                if ((target - sum) % coin2 == 0)
                {
                    count = i + (target - sum) / coin2;
                    break;
                }
            }
            printf("%d\n", count);
        }
    }
    return 0;
}