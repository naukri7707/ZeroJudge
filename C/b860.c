#include <stdio.h>

int main()
{
    int candy, weedle, kakuna, count, min;
    while (scanf(" %d %d", &candy, &weedle) == 2)
    {
        kakuna = count = 0;
        do
        {
            min = candy / 12;
            if (weedle < min)
                min = weedle;
            if (min)
            {
                candy -= 11 * min;
                weedle -= min;
                kakuna += min;
                count += min;
            }
            candy += kakuna;
            kakuna = 0;
            if (candy < 12)
            {
                weedle -= 12 - candy;
                candy = 12;
            }
        } while (weedle > 0);
        printf("%d\n", count);
    }
    return 0;
}