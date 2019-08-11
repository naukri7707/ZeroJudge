#include <stdio.h>

int n, m;

int main()
{
    while (scanf(" %d %d", &n, &m) == 2)
    {
        printf("%d\n", n == m ? m : m + 1);
    }
    return 0;
}