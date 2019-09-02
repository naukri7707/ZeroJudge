#include <stdio.h>

int DP[101];

int main()
{
    int n, a, b;
    scanf(" %d", &n);
    while (n--)
    {
        scanf(" %d %d", &a, &b);
        for (int i = 100; i >= a; i--)
        {
            if (DP[i] < DP[i - a] + b)
                DP[i] = DP[i - a] + b;
        }
    }
    printf("%d", DP[100]);
    return 0;
}