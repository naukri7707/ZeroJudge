#include <stdio.h>

int main()
{
    int v, a, b;
    while (scanf(" %d %d %d", &v, &a, &b) == 3)
    {
        v = b ? (v | (1 << a)) : (v & ~(1 << a));
        for (int i = 31; ~i; i--)
            putchar(((v >> i) & 1) + '0');
        putchar('\n');
    }
    return 0;
}