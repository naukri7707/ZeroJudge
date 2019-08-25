#include <stdio.h>

char s[1000];

int main()
{
    while (scanf(" %s", s) == 1)
    {
        s[0] -= 32;
        puts(s);
    }
    return 0;
}