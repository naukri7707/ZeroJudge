#include <stdio.h>
#define MAX 10001

const int money[] = { 1, 2, 4, 10, 20, 40, 100, 200, 400 };
unsigned long long list[MAX];
int n, tmp;
char input[1000], * st;

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
    for (int i = 0; i < MAX; i++)
        list[i] = 1;
    for (int i = 0; i < 9; i++)
    {
        for (int j = money[i]; j < MAX; j++)
            list[j] += list[j - money[i]];
    }
    while (gets(input) && input[0] - '0')
    {
        n = 0, st = input;
        while (st = getUInt(&tmp, st))
            n += tmp;
        printf("%llu\n", list[n / 5] - 1);
    }
    return 0;
}