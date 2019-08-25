#include <stdio.h>

char str[1000];

int main()
{
    gets(str);
    printf("Go, %s, go go", str);
    return 0;
}