#include <stdio.h>

int main()
{
    int n , num , sum;
    while (scanf(" %d", &n) == 1)
    {
        sum = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf(" %d", &num);
            sum += num * i;
        }
        printf("%d\n", sum);
    }
    return 0;
}