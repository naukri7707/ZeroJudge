#include<stdio.h>

int main()
{
    int n, tmp, max = 0;
    scanf(" %d", &n);
    while (n--)
    {
        scanf("%d", &tmp);
        if (max < tmp)
            max = tmp;
    }
    printf("%d", max);
    return 0;
}