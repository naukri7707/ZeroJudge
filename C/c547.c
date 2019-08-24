#include <stdio.h>
#define Mod 1000000007

int list[10001] = { 1, 1 };

int main()
{
    int n;
    for (int i = 2; i <= 10000; i++)
        list[i] = (list[i - 1] + list[i - 2]) % Mod;
    while (scanf("%d", &n) == 1)
    {
        printf("%d\n", list[n]);
    }
    return 0;
}