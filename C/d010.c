#include<stdio.h>

int main()
{
    int n, k;
    while (scanf(" %d", &n) == 1)
    {
        k = 0;
        for (int i = n - 1; i > 0; i--)
        {
            if (!(n % i))
                k = k + i;
        }
        if (k < n)
            puts("虧數");
        else if (k > n)
            puts("盈數");
        else
            puts("完全數");
    }
    return 0;
}