#include <stdio.h>
#define SWAP(x, y) (x)^=((y)^=((x)^=(y)))

inline int lcm(long long m, int n)
{
    long long res = m * n;
    while (n)
    {
        m %= n;
        SWAP(m, n);
    }
    return res / m;
}

int main()
{
    int n, ans, tmp;
    while (scanf(" %d %d", &n, &ans) == 2 && n)
    {
        while (--n)
        {
            scanf(" %d", &tmp);
            ans = lcm(ans, tmp);
        }
        printf("%d\n", ans);
    }
    return 0;
}