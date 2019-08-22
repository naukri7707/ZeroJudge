#include <stdio.h>
#include <string.h>
#define MAX 10000

char name[MAX], hello[MAX], * hs, * h;

int main()
{
    fgets(name, MAX, stdin);
    fgets(hello, MAX, stdin);
    h = hello + strlen(hello);
    *h++ = ',', * h++ = ' ';
    hs = h;
    for (int i = 0; name[i]; i++)
    {
        if (name[i] == ' ')
            * h = '\0', puts(hello), h = hs;
        else
            *h++ = name[i];
    }
    *h = '\0', puts(hello);
    return 0;
}