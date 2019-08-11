#include <stdio.h>

char str[10];

int main()
{
    while (scanf(" %s", str) == 1)
    {
        for (int i = 0; i < 6; i++)
            printf("%d", str[i] > str[i + 1] ? str[i] - str[i + 1] : str[i + 1] - str[i]);
        putchar('\n');
    }
    return 0;
}