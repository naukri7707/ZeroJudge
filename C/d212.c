#include <stdio.h>
#define SIZE 100
#define MAX 10000000000000000000ULL

unsigned long long list[SIZE] = { 1, 1 };
int list2[SIZE];

int main()
{
    int n;
    for (int i = 2; i < SIZE; i++)
    {
        list[i] = list[i - 1] + list[i - 2];
        list2[i] = list2[i - 1] + list2[i - 2];
        if (list[i] >= MAX)
            list[i] -= MAX, list2[i]++;
    }
    while (scanf(" %d", &n) == 1)
    {
        if (list2[n]) printf("%d%012llu\n", list2[n], list[n]); 
        else printf("%llu\n", list[n]);
    }
    return 0;
}