#include <stdio.h>

int main()
{
    int kase, n, k;
    long long ans;
    scanf(" %d", &kase);
    while (kase--)
    {
        scanf(" %d %d", &n, &k);
        ans = 1;
        for (int i = n; i > k; i--)
            ans *= i;
        for (int i = n - k; i > 1; i--)
            ans /= i;
        printf("%lld\n", ans);
    }
    return 0;
}