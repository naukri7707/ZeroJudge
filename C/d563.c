#include <stdio.h>

int list[100010];

int main()
{
    int n, sumL, sumR, count = 0;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
        scanf(" %d", list + i);
    sumL = list[0], sumR = list[n - 1];
    for (int l = 0, r = n - 1; l < n && ~r;)
    {
        if (sumL > sumR)
            sumR += list[--r];
        else if (sumR > sumL)
            sumL += list[++l];
        else
        {
            sumR += list[--r];
            sumL += list[++l];
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}