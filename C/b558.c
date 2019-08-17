#include <stdio.h>
#define MAX 500

int list[MAX - 1] = { 0,1 };

int main()
{
    int n;
    for (int i = 1; i < MAX; i++)
        list[i + 1] = list[i] + i;
    while (scanf(" %d", &n) == 1)
    {
        printf("%d\n", list[n]);
    }
    return 0;
}