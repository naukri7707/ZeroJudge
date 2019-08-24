#include <stdio.h>

char s[101];

int main()
{
    int n;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
        s[i] = '_';
    for (int i = n - 1; i >= 0; i--)
    {
        s[i] = '*';
        puts(s);
    }
    return 0;
}