#include <stdio.h>

unsigned long long steps;
int step[35], n, base;
char now[35], to[35], end[35], curr;

int main()
{
    for (int i = 0; i < 31; i++)
        step[i] = 1 << i;
    while (scanf(" %d", &n) == 1 && n)
    {
        steps = 0, base = 1;
        for (int i = 1; i <= n; i++)
            scanf(" %d", &now[i]);
        for (int i = 1; i <= n; i++)
            scanf(" %d", &end[i]);
        while (now[n] == end[n] && n)
            n--;
        if (n)
        {
            while (now[base + 1] == now[1] && base < n - 1)
                base++;
            to[n] = end[n];
            for (int i = n; i > 1; i--)
                to[i - 1] = now[i] == to[i] ? to[i] : 6 - now[i] - to[i];
            curr = now[base];
            for (int i = base + 1; i <= n; i++)
            {
                if (now[i] == to[i]) continue;
                if (now[i] + to[i] + curr == 6)
                    steps++;
                else
                    steps += step[base], base = i - 1, curr = 6 - now[i] - to[i];
            }
            curr = to[n - 1];
            for (int i = base; i; i--)
            {
                if (curr == end[i]) continue;
                curr = 6 - curr - end[i];
                steps += step[i - 1];
            }
            printf("%llu\n", steps);
        }
        else
        {
            puts("0");
        }
    }
    return 0;
}