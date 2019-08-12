#include<stdio.h>

int kase, sum;
char n[15];

int main()
{
    scanf(" %d", &kase);
    while (kase--)
    {
        scanf(" %s", n);
        sum = 1;
        for (int i = 0; n[i]; i++)
            sum *= n[i] - '0';
        printf("%d\n", sum);
    }
    return 0;
}