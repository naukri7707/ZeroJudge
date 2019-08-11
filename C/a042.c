#include <stdio.h>

int n;

int main()
{
    while (scanf("%d", &n) == 1)
    {
        printf("%d\n", n * n - n + 2);
    }
    return 0;
}