#include<stdio.h>

int n, m, sum, count;

int main()
{
    while (scanf(" %d %d", &n, &m) == 2)
    {
        sum = n , count = 1;
        while (sum <= m)
            sum += n + count++;
        printf("%d\n", count);
    }
    return 0;
}