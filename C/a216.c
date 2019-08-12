#include<stdio.h>
#define MAX 30001

int n;
int  f[MAX];
long long g[MAX];

int main()
{
    for (int i = 1; i < MAX; i++)
    {
        f[i] = i + f[i - 1];
        g[i] = f[i] + g[i - 1];
    }
    while (scanf(" %d", &n) == 1)
    {
        printf("%d %lld\n", f[n], g[n]);
    }
    return 0;
}