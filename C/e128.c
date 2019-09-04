#include <stdio.h>
#include <math.h>

int main()
{
    int n, sr, pos;
    while (scanf(" %d", &n) == 1 && n)
    {
        sr = sqrt((double)n);
        if (sr * sr == n)
            sr--;
        n -= sr * sr;
        pos = sr + 1;
        if (pos & 1)
        {
            if (n < pos)
                printf("%d %d\n", pos, n);
            else
                printf("%d %d\n", (pos << 1) - n, pos);
        }
        else
        {
            if (n < pos)
                printf("%d %d\n", n, pos);
            else
                printf("%d %d\n", pos, (pos << 1) - n);
        }
    }
    return 0;
}