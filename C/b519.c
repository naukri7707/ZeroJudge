#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int suit, num;
}Poker;

cmp(const Poker* lhs, const Poker* rhs)
{
    return lhs->num - rhs->num;
}

int main()
{
    Poker list[5];
    int kase, tmp, count, s, n;
    scanf(" %d", &kase);
    while (kase--)
    {
        int  pair[5] = { 0 };
        for (int i = 0; i < 5; i++)
        {
            scanf(" %d", &tmp);
            count = 1, tmp--;
            list[i].suit = tmp / 13;
            list[i].num = tmp % 13;
            for (int j = i - 1; ~j; j--)
            {
                if (list[j].num == list[i].num)
                    count++;
            }
            pair[count]++, pair[count - 1]--;
        }
        if (pair[4]) puts("6");
        else if (pair[3])
        {
            if (pair[2]) puts("5");
            else puts("3");
        }
        else if (pair[2])
        {
            if (pair[2] == 2) puts("2");
            else puts("1");
        }
        else
        {
            qsort(list, 5, sizeof(Poker), cmp);
            s = n = 1;
            for (int i = 1; i < 4; i++)
            {
                if (list[i].num - 1 != list[i - 1].num)
                {
                    n = 0;
                    break;
                }
                if (list[i].suit != list[i - 1].suit)
                    s = 0;
            }
            if (n)
            {
                if (s) puts("7");
                else puts("4");
            }
            else puts("0");
        }
    }
    return 0;
}