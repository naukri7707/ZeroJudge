#include <stdio.h>

int n, m , arms[20], aLen;
char hasAns;

inline int pow(int src, int p)
{
    int res = src;
    while (--p)
        res *= src;
    return res;
}

void SetArmsList()
{
    int now = 0, tmp[6], i, j, k, sum;
    for (i = 1; i < 1000000; i++)
    {
        now = i, j = k = sum = 0;
        for (; now; j++, now /= 10)
            tmp[j] = now % 10;
        for (; k < j; k++)
            sum += pow(tmp[k], j);
        if (sum == i)
            arms[aLen++] = i;
    }
}

int main()
{
    SetArmsList();
    while (scanf(" %d %d", &n, &m) == 2)
    {
        hasAns = 0;
        for (int i = 0; i < aLen && arms[i] <= m; i++)
        {
            if (arms[i] >= n)
                printf("%d ", arms[i]) , hasAns = 1;
        }
        if (hasAns)
            putchar('\n');
        else
            puts("none");
    }
    return 0;
}