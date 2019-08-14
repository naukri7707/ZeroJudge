#include <stdio.h>
#define MAX 30000

int num[MAX + 1];

int main()
{
    int n, tmp, max = 0;
    scanf(" %d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf(" %d", &tmp);
        num[tmp]++;
        if (max < num[tmp])
            max = num[tmp];
    }
    for (int i = 1; i <= MAX; i++)
        if (num[i] == max) printf("%d %d\n", i , max); 
    return 0;
}