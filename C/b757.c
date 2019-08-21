#include <stdio.h>

int main()
{
    double n;
    while (scanf(" %lf", &n) == 1)
    {
        printf("%g\n", (n * 9) / 5 + 32);
    }
    return 0;
}