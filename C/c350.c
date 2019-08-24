#include <stdio.h>

int main()
{
    int n, k, w, m, sum, gap;
    scanf(" %d %d %d", &n, &k, &w);
    sum = n, gap = k - w;
    for (int i = n / k; i; i = n / k)
        sum += w * i, n -= gap * i;
    printf("%d\n", sum);
    return 0;
}