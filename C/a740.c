#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 47000

int primeList[5000], pLen;

int cmp(const int* lhs, const int* rhs)
{
    return *lhs - *rhs;
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

char isPrime(int n)
{
    if (n < MAX)
    {
        int* item = (int*)bsearch(&n, primeList, pLen, sizeof(int), cmp);
        return (item != NULL);
    }
    else
    {
        for (int i = 0, max = sqrt(n); primeList[i] <= max; i++)
        {
            if (!(n % primeList[i]))
                return 0;
        }
        return 1;
    }
}

int main()
{
    SetPrimeList();
    int n, ans;
    while (scanf(" %d", &n) == 1)
    {

        if (isPrime(n))
            printf("%d\n", n);
        else
        {
            ans = 0;
            for (int i = 0; n > 1; i++)
            {
                while (!(n % primeList[i]))
                {
                    n /= primeList[i];
                    ans += primeList[i];
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}