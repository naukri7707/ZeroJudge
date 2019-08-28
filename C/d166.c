#include <stdio.h>
#define MAX 55

char input[10000];

inline char* getUInt(unsigned int* dst, char src[])
{
    while (*src < '0')
        if (!*src++) return NULL;
    *dst = *src ^ '0';
    while (*++src >= '0')
        * dst = (*dst << 3) + (*dst << 1) + (*src ^ '0');
    return src;
}

int main()
{
    while (gets(input) && input[0] != '-')
    {
        char* st = input;
        int ans[MAX] = { 0 }, tmp, j;
        for (int i = 0; st = getUInt(&tmp, st); i++)
        {
            for (j = 0; tmp || ans[j]; j++)
                if (!ans[j]) tmp--;
            ans[j] = i + 1;
        }
        for (int i = 0; ans[i]; i++)
            printf("%d ", ans[i]);
        putchar('\n');
    }
    return 0;
}
