#include <stdio.h>

int n;
char Zodiac[][4] = { "豬", "鼠", "牛", "虎", "兔", "龍", "蛇", "馬", "羊", "猴", "雞", "狗" };

int main()
{
    while (scanf(" %d", &n) == 1)
    {
        puts(Zodiac[(n < 0 ? n + 121 : n) % 12]);
    }
    return 0;
}