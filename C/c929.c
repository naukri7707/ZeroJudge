#include <stdio.h>
#define SIZE 2000

int oLen;
char spilt[SIZE], input[SIZE], output[SIZE];

inline int strspt(int* idx, char* spilt)
{
    int i = 0;
    for (; spilt[i]; i++)
    {
        if (input[*idx + i] != spilt[i] || !input[*idx + i])
            return 0;
    }
    *idx += i - 1;
    return 1;
}

int main()
{
    gets(spilt), gets(input);
    for (int i = 0; input[i]; i++)
    {
        if (strspt(&i, spilt))
            output[oLen++] = '\n';
        else
            output[oLen++] = input[i];
    }
    puts(output);
    return 0;
}