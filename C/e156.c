#include <stdio.h>

int n, sum;

int dfs()
{
    return (sum += n) && --n && dfs();
}

int main()
{
    scanf(" %d", &n);
    dfs();
    printf("%d", sum);
    return 0;
}