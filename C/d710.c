#include <stdio.h>
#include <string.h>
#define MAX 25

typedef struct Node
{
    char brand[MAX], color[MAX];
}Car;

Car list[MAX];

int main()
{
    int n, m;
    char type[MAX], target[MAX];
    while (scanf(" %d %d", &n, &m) == 2)
    {
        for (int i = 0; i < n; i++)
            scanf(" %s %s", &list[i].brand, &list[i].color);
        while (m--)
        {
            scanf(" %s %s", type, target);
            if (type[0] == 'b')
            {
                for (int i = 0; i < n; i++)
                {
                    if (!strcmp(target, list[i].brand))
                        printf("%s %s\n", list[i].brand, list[i].color);
                }
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    if (!strcmp(target, list[i].color))
                        printf("%s %s\n", list[i].brand, list[i].color);
                }
            }
            putchar('\n');
        }
    }
    return 0;
}