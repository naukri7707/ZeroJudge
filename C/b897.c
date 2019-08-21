#include <stdio.h>
#include <math.h>

int main()
{
    register double log;
    int n, k, max;
    while (scanf(" %d %d", &k, &n) == 2)
    {
        log = 0, max = n < k - n ? n : k - n;
        for (int i = 0; i < max; i++)
            log += log10(k - i) - log10(i + 1);
        printf("%d\n", (int)log + 1);
    }
    return 0;
}