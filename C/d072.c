#include<stdio.h>

int main()
{
    int kase, y;
    scanf(" %d", &kase);
    for (int i = 1; i <= kase; i++)
    {
        scanf(" %d", &y);
        if (!(y % 400) || !(y % 4) && (y % 100))
            printf("Case %d: a leap year\n", i);
        else
            printf("Case %d: a normal year\n", i);
    }
    return 0;
}