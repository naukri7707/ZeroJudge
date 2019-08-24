#include <stdio.h>
#define MAX 100001
#define MOD 1000000007

int DP[MAX] = { 1, 1, 1 }, n, m, kinder, pKinder;
long long ans = 1;

int main()
{
    for (int i = 3; i < MAX; i++)
        DP[i] = (DP[i - 1] + DP[i - 3]) % MOD;
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf(" %d", &kinder);
        ans = (ans * DP[kinder - pKinder]) % MOD;
        pKinder = kinder;
    }
    printf("%lld\n", (ans * DP[n - pKinder]) % MOD);
    return 0;
}