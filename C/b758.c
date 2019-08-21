#include <stdio.h>

int main()
{
    int h, m;
    while (scanf(" %d %d", &h, &m) == 2)
    {
        m += h * 60 + 150;
        h = m / 60, m = m % 60;
        printf("%02d:%02d\n", h < 24 ? h : h - 24, m);
    }
    return 0;
}