#include <stdio.h>
#define MAX 201

int main()
{
    unsigned long long int list[MAX] = { 1 };
    int n;
    for (int i = 1; i < MAX; i++)
    {
        for (int j = i; j < MAX; j++)
            list[j] += list[j - i];
    }
    while (scanf(" %d", &n) == 1)
    {
        printf("%llu\n", list[n]);
    }
    return 0;
}