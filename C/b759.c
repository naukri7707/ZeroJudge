#include <stdio.h>
#include <string.h>

char s[2000010];

int main()
{
    gets(s);
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        puts(s + i);
        s[len + i] = s[i];
    }
    return 0;
}