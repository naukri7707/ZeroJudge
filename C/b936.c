#include <stdio.h>

long long n, m;

long long dfs(long long piece)
{
    if ((piece >> 1) < m)
        return 1;
    if (piece & 1)
        return dfs((piece + 1) >> 1) + dfs((piece - 1) >> 1);
    else
        return dfs(piece >> 1) << 1;
}

int main()
{
    while (scanf(" %lld %lld", &n, &m) == 2)
    {
        printf("%lld\n", n < m ? 0 : dfs(n));
    }
    return 0;
}