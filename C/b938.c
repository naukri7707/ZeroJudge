#include <stdio.h>
#define MAX 1000010

typedef struct Node
{
    int Next;
    char Alive;
}Player;

Player list[MAX];
int n, m;

int main()
{
    while (scanf(" %d %d", &n, &m) == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            list[i].Alive = 1;
            list[i].Next = i + 1;
        }
        list[n + 1].Alive = 0;
        for (int i = 0, k; i < m; i++)
        {
            scanf(" %d", &k);
            if (list[k].Alive && list[list[k].Next].Alive)
            {
                printf("%d\n", list[k].Next);
                list[list[k].Next].Alive = 0;
                list[k].Next = list[list[k].Next].Next;
            }
            else
            {
                puts("0u0 ...... ?");
            }
        }
    }
    return 0;
}