#include <stdio.h>

int main()
{
    int s, e, d;
    while (scanf(" %d %d %d", &s, &e, &d) == 3)
    {
        for (; s != e; s += d)
            printf("%d ", s);
        printf("%d\n", e);
    }
    return 0;
}