#include <stdio.h>

int n;

int main()
{
    while (scanf(" %d", &n) == 1)
    {
        if (n < 10)
            printf("%d\n", n * 6);
        else if (n < 20)
            printf("%d\n", 60 + (n - 10) * 2);
        else if (n < 40)
            printf("%d\n", 80 + n - 20);
        else
            puts("100");
    }
    return 0;
}