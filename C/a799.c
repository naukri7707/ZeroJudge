#include <stdio.h>

int main()
{
    int n;
    while (scanf(" %d", &n) == 1)
    {
        printf("%d\n", n < 0 ? -n : n);
    }
    return 0;
}