#include <stdio.h>

char s[1010];

int main()
{
    gets(s);
    for (int i = 1; s[i + 1]; i++)
        s[i] = '_';
    puts(s);
    return 0;
}