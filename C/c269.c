#include <stdio.h>

unsigned long long favor[1010];

int main()
{
    unsigned long long  gFavor;
    int girls, times, gTime, gType;
    char flag;
    scanf(" %d %d", &girls, &times);
    for (int h = 0; h < girls; h++)
    {
        scanf("%d %llu %d", &gTime, &gFavor, &gType);
        gFavor *= 100000;
        if (gType == 1)
        {
            gFavor = gFavor / gTime;
            do
            {
                flag = 0;
                for (int i = times; i >= 1; i--)
                {
                    if (favor[i - 1] + gFavor > favor[i])
                    {
                        favor[i] = favor[i - 1] + gFavor;
                        flag = 1;
                    }
                }
            } while (--gTime && flag);
        }
        else
        {
            for (int i = times; i >= gTime; i--)
            {
                if (favor[i - gTime] + gFavor > favor[i])
                    favor[i] = favor[i - gTime] + gFavor;
            }
        }
    }
    printf("%llu\n", (favor[times] + 50000) / 100000);
    return 0;
}