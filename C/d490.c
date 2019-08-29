#include <stdio.h>

int main()
{
    int n, m;
    scanf(" %d %d", &n, &m);
    n += (n & 1), m -= (m & 1);
    printf("%d\n", ((n + m) * ((m - n) / 2 + 1)) / 2);
    return 0;
}