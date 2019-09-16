#include <stdio.h>

int main()
{
    int n, lhs[5], rhs[5], count;
    scanf(" %d", &n);
    while (n--)
    {
        scanf(" %d , %d , %d , %d , %d", &lhs[0], &lhs[1], &lhs[2], &lhs[3], &lhs[4]);
        scanf(" %d , %d , %d , %d , %d", &rhs[0], &rhs[1], &rhs[2], &rhs[3], &rhs[4]);
        count = 0;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (lhs[i] == rhs[j])
                {
                    count++;
                    break;
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}