#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 47000

int primeList[5000], pLen, n;
char isPrime;

int cmp(const void* lhs, const void* rhs)
{
    return (*(int*)lhs - *(int*)rhs);
}

void SetPrimeList()
{
    char isNot[MAX] = { 0 };
    primeList[pLen++] = 2;
    for (int i = 3; i < MAX; i += 2)
    {
        if (isNot[i])continue;
        primeList[pLen++] = i;
        for (int j = i << 1; j < MAX; j += i)
            isNot[j] = 1;
    }
}

int main()
{
    SetPrimeList();
    while (scanf(" %d", &n) == 1)
    {
        isPrime = 0;
        if (n < MAX)
        {
            int* item = (int*)bsearch(&n, primeList, pLen, sizeof(int), cmp);
            isPrime = (item != NULL);
        }
        else
        {
            isPrime = 1;
            for (int i = 0, max = sqrt(n); primeList[i] <= max; i++)
            {
                if (!(n % primeList[i]))
                {
                    isPrime = 0;
                    break;
                }
            }
        }
        puts(isPrime ? "質數" : "非質數");
    }
    return 0;
}