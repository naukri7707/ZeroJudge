#include<stdio.h>

int main()
{
    int n, count;
    while (scanf(" %d", &n) && n)
    {
        count = 0;
        while (n & 1)
            count++, n >>= 1;
        printf("%d\n", count);
    }
    return 0;
}