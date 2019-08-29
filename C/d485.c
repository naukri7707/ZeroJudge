#include <stdio.h>

int main()
{
    int n, m;
    scanf(" %d %d", &n, &m);
    printf("%d\n", (m - n - (m & 1) - (n & 1)) / 2 + 1);
    return 0;
}