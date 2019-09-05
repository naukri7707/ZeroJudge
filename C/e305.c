#include <stdio.h>

unsigned long long n, ans;

int main()
{
    while (scanf(" %llu", &n) == 1)
    {
        if (n)
        {
            ans = 1;
            do
            {
                if (!(n & 1))
                    ans <<= 1;
            } while (n >>= 1);
            printf("%llu\n", ans);
        }
        else puts("0");
    }
    return 0;
}