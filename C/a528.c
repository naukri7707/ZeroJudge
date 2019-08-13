#include <stdio.h>
#include <string.h>

typedef struct node
{
    int Length;
    char Num[110];
}BigNum;

BigNum list[1000], * sort[1000];

int cmp(const BigNum** lhs, const BigNum** rhs)
{
    if ((*lhs)->Length != (*rhs)->Length)
        return (*lhs)->Length - (*rhs)->Length;
    return (*lhs)->Length < 0 ? strcmp((*rhs)->Num, (*lhs)->Num) : strcmp((*lhs)->Num, (*rhs)->Num);
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        for (int i = 0; i < n; i++)
        {
            scanf(" %s", list[i].Num);
            list[i].Length = list[i].Num[0] == '-' ? -((int)strlen(list[i].Num)) : strlen(list[i].Num);
            sort[i] = &list[i];
        }
        qsort(sort, n, sizeof(BigNum*), cmp);
        for (int i = 0; i < n; i++)
            puts(sort[i]->Num);
    }
    return 0;
}