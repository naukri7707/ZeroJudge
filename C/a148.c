#include<stdio.h>

int main()
{
    int n, m, sum;
    while (scanf(" %d", &n) == 1)
    {
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            scanf(" %d", &m);
            sum += m;
        }
        puts(sum > 59 * n ? "no" : "yes");
    }
    return 0;
}