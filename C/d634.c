#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char list[100000][11], * sort[100000];

int cmp(const char** lhs, const char** rhs)
{
    return strcmp(*lhs, *rhs);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        sort[i] = list[i];
    getchar();
    for (int i = 0; i < n; i++)
        gets(list[i]);
    qsort(sort, n, sizeof(char**), cmp);
    for (int i = 0; i < n; i++)
        puts(sort[i]);
    return 0;
}