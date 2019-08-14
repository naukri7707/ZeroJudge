#include <stdio.h>
#define SWAP(x, y) x^=(y^=(x^=y)) 

int index[10000];

int main()
{
    int n, max, count;
    while (scanf(" %d", &n) == 1)
    {
        max = n - 1, count = 0;
        for (int i = 0; i < n; i++)
            scanf(" %d", &index[i]);
        for (int i = 0; i < max; i++)
        {
            for (int j = 0; j < max - i; j++)
            {
                if (index[j] > index[j + 1])
                    SWAP(index[j], index[j + 1]), count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}