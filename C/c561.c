#include <stdio.h>

int n, tmp, convert, best;

int main()
{
    scanf(" %d", &n);
    while (n--)
    {
        convert = 0;
        scanf(" %d", &tmp);
        while (tmp)
        {
            convert = convert * 10 + (tmp % 10);
            tmp /= 10;
        }
        if (best < convert)
            best = convert;
    }
    printf("%d\n", best);
    return 0;
}