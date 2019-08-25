#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

int kase, list[1000], tmp, nLen, gap, same, miss;
char input[MAX], ans;

int cmp(const int* lhs, const int* rhs)
{
    return *lhs - *rhs;
}

void setDigitList()
{
    tmp = nLen = 0;
    for (int i = 0; input[i]; i++)
    {
        if (input[i] == ' ')
            list[nLen++] = tmp, tmp = 0;
        else
            tmp = (tmp << 3) + (tmp << 1) + (input[i] - '0');
    }
    list[nLen++] = tmp;
}

int main()
{
    scanf(" %d", &kase);
    getchar();
    while (kase--)
    {
        gets(input);
        setDigitList();
        qsort(list, nLen, sizeof(int), cmp);
        gap = (list[nLen - 1] - list[0]) / (nLen - 1), ans = 0;
        for (int i = 1; i < nLen; i++)
        {
            if (list[i] != list[i - 1] + gap)
            {
                if (list[i] == list[i - 1])
                    same = list[i], ans++;
                else
                    miss = (list[i] + list[i - 1]) >> 1, ans++;
                if (ans == 2)
                    break;
            }
        }
        printf("%d %d\n", miss, same);
    }
    return 0;
}