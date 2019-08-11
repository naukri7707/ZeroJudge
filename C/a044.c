#include <stdio.h>

int n;

int main()
{
    while (scanf("%d", &n) == 1)
    {
        printf("%d\n", (n * n * n + 5 * n + 6) / 6);
    }
    return 0;
}