#include <stdio.h>

int main()
{
    int n;
    while (scanf(" %d", &n) == 1)
    {
        printf("%d\n", n ? (n - 1) % 9 + 1 : 0);
    }
    return 0;
}