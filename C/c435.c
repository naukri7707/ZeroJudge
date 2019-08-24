#include <stdio.h>

int main()
{
    int n, max, min, tmp, best;
    while (scanf(" %d", &n) == 1)
    {
        scanf(" %d", &min);
        best = 0, max = min;
        while (--n)
        {
            scanf(" %d", &tmp);
            if (tmp < min)
                min = tmp;
            else if (tmp > max)
            {
                if (max - min > best)
                    best = max - min;
                max = min = tmp;
            }
        }
        printf("%d\n", best < max - min ? max - min : best);
    }
    return 0;
}