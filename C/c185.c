#include <stdio.h>

int main()
{
    char s[1000] = "Hey ";
    while (gets(s + 4) != NULL)
    {
        puts(s);
    }
    return 0;
}