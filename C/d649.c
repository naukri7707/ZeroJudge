#include <stdio.h>

char s[1001];

int main()
{
    int n;
    while (scanf(" %d", &n) == 1 && n)
    {
        for (int i = 0; i < n; i++)
            s[i] = '_';
        s[n] = '\0';
        for (int i = n - 1; i >= 0; i--)
        {
            s[i] = '+';
            puts(s);
        }
    }
    return 0;
}