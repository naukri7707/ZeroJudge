#include <stdio.h>
#define MOD 10007

int flt(int a, int b)
{
    int res = 1, next = a % MOD;
    for (int i = 0; i < 32; i++)
    {
        if (b & 1)
            res = res * next % MOD;
        next = next * next % MOD;
        b >>= 1;
    }
    return res;
}

int main()
{
    int a, b;
    scanf(" %d %d", &a, &b);
    printf("%d\n", flt(a, b));
    return 0;
}