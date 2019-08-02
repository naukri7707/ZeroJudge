#include <stdio.h>

int y;

int main()
{
    while (scanf(" %d", &y) == 1)
    {
        if (y % 400 == 0)
        {
            puts("閏年");
        }
        else if (y % 4 == 0 && y % 100 != 0)
        {
            puts("閏年");
        }
        else
        {
            puts("平年");
        }
    }
    return 0;
}