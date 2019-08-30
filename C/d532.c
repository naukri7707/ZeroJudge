#include <stdio.h>

int main()
{
    int n, m, cont = 0;
    scanf(" %d %d", &n, &m);
    for (int i = n; i <= m; i++)
    {
        if (!(i % 400) || (i % 100) && !(i % 4))
            cont++;
    }
    printf("%d\n", cont);
    return 0;
}