#include <stdio.h>

int main()
{
    int h, m;
    scanf(" %d %d", &h, &m);
    if (h == 7 && m >= 30 || h > 7 && h < 17)
        puts("At School");
    else
        puts("Off School");
    return 0;
}