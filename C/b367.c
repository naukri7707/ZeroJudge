#include <stdio.h>

int main()
{
    int kase, n, m, s, e, list[150];
    scanf(" %d", &kase);
    while (kase--)
    {
        scanf(" %d %d", &n, &m);
        s = 0, e = n * m - 1;
        for (int i = 0; i <= e; i++)
            scanf(" %d", &list[i]);
        while (list[s] == list[e])
        {
            if (s > e)
                break;
            s++, e--;
        }
        puts(s < e ? "keep defending" : "go forward");
    }
    return 0;
}