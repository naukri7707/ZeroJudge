#include <stdio.h>

char sky[][4] = { "甲", "乙", "丙", "丁", "戊", "己", "庚", "辛", "壬", "癸" };
char grd[][4] = { "子", "丑", "寅", "卯", "辰", "巳", "午", "未", "申", "酉", "戌", "亥" };

int main()
{
    int n;
    while (scanf(" %d", &n) == 1)
    {
        n = (n - 1744) % 60;
        printf("%s%s\n", sky[n % 10], grd[n % 12]);
    }
    return 0;
}