#include <stdio.h>

int main()
{
    int kase, h1, m1, h2, m2, t;
    scanf("%d\n", &kase);
    while (kase--)
    {
        scanf(" %d %d %d %d %d", &h1, &m1, &h2, &m2, &t);
        m1 += h1 * 60 + t;
        m2 += h2 * 60;
        puts(m1 > m2 ? "No" : "Yes");
    }
    return 0;
}