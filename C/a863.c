#include <stdio.h>

int main()
{
    int n, now, tmp;
    while (scanf(" %d", &n) == 1)
    {
        for (now = n; now != 1 && now != 4; now = tmp)
        {
            tmp = 0;
            while (now)
            {
                tmp += (now % 10) * (now % 10);
                now /= 10;
            }
        }
        if (now == 1)
            printf("%d is a happy number\n", n);
        else if (now == 4)
            printf("%d is an unhappy number\n", n);
    }
    return 0;
}