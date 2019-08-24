#include <stdio.h>

int n, tmp, list[101];

int main()
{
    scanf(" %d", &n);
    while (n--)
    {
        scanf(" %d", &tmp);
        list[tmp]++;
    }
    for (int i = 1; i <= 100; i++)
    {
        while (list[i]--)
            printf("%d ", i);
    }
    return 0;
}