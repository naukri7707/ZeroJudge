#include <stdio.h>
#define MAX 32

int kase, f, t, sq[MAX];

int main()
{
    for (int i = 0; i < MAX; i++)
        sq[i] = i * i;
    while (scanf(" %d", &kase) == 1)
    {
        for (int kas = 1; kas <= kase; kas++)
        {
            scanf(" %d %d", &f, &t);
            int i = 0, sum = 0;
            while (sq[i] < f)
                i++;
            do
            {
                sum += sq[i];
            } while (++i < MAX && sq[i] <= t);
            printf("Case %d: %d\n", kas, sum);
        }
    }
    return 0;
}