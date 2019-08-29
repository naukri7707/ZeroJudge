#include <stdio.h>
#define SWAP(x, y) (x)^=((y)^=((x)^=(y)))

int main()
{
    int n, m;
    scanf(" %d %d", &n, &m);
    if (m < n) SWAP(n, m);
    n += (n & 1), m -= (m & 1);
    printf("%d\n", ((n + m) * ((m - n) / 2 + 1)) / 2);
    return 0;
}