#include <stdio.h>
#define SWAP(x, y) \
    x = x ^ y,     \
    y = x ^ y,     \
    x = x ^ y

int m, n;

int main()
{
    while (scanf(" %d %d", &m , &n) == 2)
    {
        while (n)
        {
            m %= n;
            SWAP(m, n);
        }
        printf("%d\n", m);
    }
    return 0;
}