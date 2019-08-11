#include <stdio.h>
#define SWAP(x, y) \
    x = x ^ y,     \
    y = x ^ y,     \
    x = x ^ y

int n, list[1010];

int main()
{
    while (scanf(" %d", &n) == 1)
    {
        scanf(" %d", &list[0]);
        for (int i = 1; i < n; i++)
        {
            scanf(" %d", &list[i]);
            for (int j = i; j && list[j] < list[j - 1]; j--)
                SWAP(list[j], list[j - 1]);
        }
        for (int i = 0; i < n; i++)
            printf("%d ", list[i]);
        putchar('\n');
    }
    return 0;
}