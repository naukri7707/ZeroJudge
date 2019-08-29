#include <stdio.h>
#include <stdlib.h>

int cmp(const int* lhs, const int* rhs)
{
    return *lhs - *rhs;
}

int main()
{
    int list[3], ans = 0;
    for (int h = 0; h < 5; h++)
    {
        for (int i = 0; i < 3; i++)
            scanf(" %d", &list[i]);
        qsort(list, 3, sizeof(int), cmp);
        if (list[0] + list[1] > list[2]) ans++;
    }
    printf("%d\n", ans);
    return 0;
}