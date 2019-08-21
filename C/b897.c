#include <stdio.h>
#include <math.h>

int main()
{
    register double log;
    int n, k, max;
    while (scanf(" %d %d", &n, &k) == 2)
    {
        log = 0, max = k < n - k ? k : n - k;
        for (int i = 0; i < max; i++)
            log += log10(n - i) - log10(i + 1);
        printf("%d\n", (int)log + 1);
    }
    return 0;
}