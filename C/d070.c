﻿#include<stdio.h>

int main()
{
    int y;
    while (scanf(" %d", &y) == 1 && y)
    {
        if (!(y % 400) || !(y % 4) && (y % 100))
            puts("a leap year");
        else
            puts("a normal year");
    }
    return 0;
}