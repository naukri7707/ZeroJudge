#include <stdio.h>

char s[200];

int main()
{
    int n;
    scanf(" %d", &n);
    for (int i = n * 2 - 2; i >= 0; i--)
        s[i] = '_';
    n--;
    for (int i = 0; i <= n; i++)
    {
        s[n - i] = s[n + i] = '*';
        puts(s);
    }
    return 0;
}