#include <stdio.h>
#define SIZE 10000

char input[SIZE], output[SIZE], conj[100], cLen, i, oLen;

int main()
{
    gets(input);
    for (i = 0; input[i] != ' '; i++)
        conj[cLen++] = input[i];
    i++;
    for (; input[i]; i++)
    {
        output[oLen++] = input[i];
        if (input[i] == ' ')
        {
            for (int j = 0; j < cLen; j++)
                output[oLen++] = conj[j];
            output[oLen++] = ' ';
        }
    }
    puts(output);
    return 0;
}