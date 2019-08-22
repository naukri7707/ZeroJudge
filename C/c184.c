#include <stdio.h>
#include <math.h>

int factorSum(int src)
{
    int end = sqrt(src), res = end * end == src ? 1 - end : 1;
    for (int i = 2; i <= end; i++)
    {
        if (!(src % i))
            res += i + src / i;
    }
    return res;
}

int main()
{
    int n, fs;
    while (scanf(" %d", &n) == 1 && n)
    {
        fs = factorSum(n);
        if (fs == n)
            printf("=%d\n", n);
        else
            printf("%d\n", factorSum(fs) == n ? fs : 0);
    }
    return 0;
}