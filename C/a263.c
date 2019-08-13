#include <stdio.h>
#define ABS(x) (x) < 0 ? -(x) : (x)

typedef struct node
{
    int Year, Month, Day;
}Date;

Date f, t;

int month[] = { 0 , 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
int fDays, tDays , gap;

inline int Days(Date src)
{
    return src.Year * 365 + (src.Year - 1) / 4 - (src.Year - 1) / 100 + (src.Year - 1) / 400 + month[src.Month - 1] + src.Day
        + ((!(src.Year % 4) && (src.Year % 100) || !(src.Year % 400)) && src.Month > 2);
}

int main()
{
    while (scanf(" %d %d %d %d %d %d", &f.Year, &f.Month, &f.Day, &t.Year, &t.Month, &t.Day) == 6)
    {
        gap = Days(f) - Days(t);
        printf("%d\n", ABS(gap));
    }
    return 0;
}