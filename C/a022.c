#include <stdio.h>
#include <string.h>

char str[1000] , isNot;

int main()
{
    while (scanf(" %s", str) == 1)
    {
        isNot = 0;
        for (int i = 0, j = strlen(str) - 1; i < j; i++, j--)
        {
            if (str[i] != str[j])
            {
                isNot = 1;
                break;
            }
        }
        if (isNot)
            puts("no");
        else
            puts("yes");
    }
    return 0;
}