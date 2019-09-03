#include <stdio.h>
#include <stdlib.h>
#define MAX 100010

int len, len2;
char input[MAX], * sort[MAX], output[MAX], * oTop;

int cmpsrc(int strLen)
{
    int k = 0;
    for (int i = 0; i < len2; i++)
    {
        for (int j = 0; j < strLen; j++)
        {
            if (sort[i][j] != input[k++])
                return 1;
        }
    }
    return 0;
}

int cmp(const char** lhs, const char** rhs)
{
    return strcmp(*lhs, *rhs);
}

int main()
{
    gets(input);
    for (len = 0; input[len]; len++)
        ;
    for (int i = 1; i < len; i++)
    {
        if (!(len % i))
        {
            len2 = len / i;
            for (int j = 0; j < len2; j++)
                sort[j] = &input[j * i];
            qsort(sort, len2, sizeof(char**), cmp);
            if (cmpsrc(i))
            {
                oTop = output;
                for (int j = 0; j < len2; j++)
                {
                    for (int k = 0; k < i; k++)
                        * oTop++ = sort[j][k];
                }
                *oTop = '\0';
                puts(output);
            }
        }
    }
    if (!oTop) puts("bomb!");
    return 0;
}