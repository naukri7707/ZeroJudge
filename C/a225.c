#include <stdio.h>
#include <stdlib.h>

int n, list[1010];

int cmp(const void* lhs, const void* rhs)
{
    int res = *(int*)lhs % 10 - *(int*)rhs % 10;
    return res ? res : *(int*)rhs - *(int*)lhs;
}

int main()
{
    while (scanf(" %d", &n) == 1)
    {
        for (int i = 0; i < n; i++)
            scanf(" %d", &list[i]);
        qsort(list, n, sizeof(int), cmp);
        for (int i = 0; i < n; i++)
            printf("%d ", list[i]);
        putchar('\n');
    }
    return 0;
}