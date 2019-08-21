#include <stdio.h>

int pow[81][6];

int main()
{
    for (int i = -40; i <= 40; i++)
    {
        pow[40 + i][1] = i;
        pow[40 + i][2] = i * i;
        pow[40 + i][3] = pow[40 + i][2] * i;
        pow[40 + i][4] = pow[40 + i][3] * i;
        pow[40 + i][5] = pow[40 + i][4] * i;
    }
    long long fa, fb, a;
    int b, c, d, e, f;
    char noAns;
    while (scanf(" %lld %d %d %d %d %d", &a, &b, &c, &d, &e, &f) == 6)
    {
        if (a || b || c || d || e || f)
        {
            noAns = 1;
            fa = a * pow[0][5] + b * pow[0][4] + c * pow[0][3] + d * pow[0][2] + e * pow[0][1] + f;
            for (int i = 1; i <= 80; i++)
            {
                fb = a * pow[i][5] + b * pow[i][4] + c * pow[i][3] + d * pow[i][2] + e * pow[i][1] + f;
                if (!fb)
                    printf("%d %d\n", pow[i][1], pow[i][1]), noAns = 0;
                else if ((fa ^ fb) < 0 && fa)
                    printf("%d %d\n", pow[i - 1][1], pow[i][1]), noAns = 0;
                fa = fb;
            }
            if (noAns)
                puts("N0THING! >\\\\\\<");
        }
        else
        {
            puts("Too many... = =\"");
        }
    }
    return 0;
}