#include <stdio.h>

char str[1000];

int main()
{
    gets(str);
    printf("%s %s\n", str, str);
    return 0;
}