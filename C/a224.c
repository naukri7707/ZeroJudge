#include <stdio.h>

char input[1100];

void strupr(char *src)
{
    src--;
    while (*++src)
    {
        if (*src >= 'a' && *src <= 'z')
            *src -= 32;
    }
}

int main()
{
    while (scanf(" %s", input) == 1)
    {
        char count[256] = { 0 }, isPal = 2;
        strupr(input);
        for (int i = 0; input[i]; i++)
            count[input[i]]++;
        for (int i = 'A'; i <= 'Z'; i++)
        {
            if (count[i] & 1)
            {
                isPal--;
                if (isPal == 0)
                    break;
            }
        }
        puts(isPal ? "yes !" : "no...");
    }
    return 0;
}