#include <stdio.h>

int main()
{
    unsigned long long n;
    int count;
    while (scanf(" %llu", &n) == 1)
    {
        count = 0;
        while (n)
        {
            n >>= 1;
            count++;
        }
        printf("%d\n", count);
    }
    return 0;
}