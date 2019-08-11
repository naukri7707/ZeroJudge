#include <stdio.h>

int n , m;

int main()
{
    while (scanf(" %d", &n) == 1)
    {
        int rem[3] = { 0 };
        while (n--)
        {
            scanf(" %d", &m);
            rem[m % 3]++;
        }
        printf("%d %d %d\n", rem[0], rem[1], rem[2]);
    }
    return 0;
}