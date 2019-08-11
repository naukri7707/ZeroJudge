#include <stdio.h>
#include <string.h>

int input;
char src[15], rev[15], * output;

int main()
{
    while (scanf(" %d", &input) == 1)
    {
        sprintf(src, " %d", input);
        output = &rev[14];
        for (int i = 0; src[i]; i++)
        {
            *output-- = src[i];
        }
        printf("%d\n", atoi(++output));
    }
    return 0;
}