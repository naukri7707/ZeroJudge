#include <stdio.h>

int n;

int main()
{
    while (scanf(" %d", &n) == 1 && n)
    {
        for (int i = 1; i < n; i++)
        {
            if (i % 7)
                printf("%d ", i);
        }
        putchar('\n');
    }
    return 0;
}