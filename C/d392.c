#include <stdio.h>

inline char* getUInt(unsigned int* dst, char src[])
{
    while (*src < '0')
        if (!*src++) return NULL;
    *dst = *src ^ '0';
    while (*++src >= '0')
        * dst = (*dst << 3) + (*dst << 1) + (*src ^ '0');
    return src;
}

char input[10000];

int main()
{
    int sum, tmp;
    char* st;
    while (gets(input))
    {
        sum = 0 , st = input;
        while (st = getUInt(&tmp , st))
            sum += tmp;
        printf("%d\n", sum);
    }
    return 0;
}