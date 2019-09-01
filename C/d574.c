#include <stdio.h>
#define MAX 10000000

char input[MAX], output[MAX];

char* setUInt(char buffer[], register unsigned int src, const char suffix)
{
    register unsigned int div;
    char tmp[11], * st = tmp + 10, *res = buffer - 1;
    *st = 0;
    do
    {
        *(--st) = src - ((div = src / 10) << 3) - (div << 1) + '0';
    } while (src = div);
    while (*++res = *st++)
        ;
    if (suffix)* res++ = suffix;
    return res;
}

int main()
{
    int n, count;
    char curr, * oTop;
    while (scanf(" %d %s", &n, input) == 2)
    {
        curr = input[0], count = 1, oTop = output;
        for (int i = 1; i < n; i++)
        {
            if (curr == input[i])
                count++;
            else
            {
                oTop = setUInt(oTop, count, curr);
                curr = input[i], count = 1;
            }
        }
        oTop = setUInt(oTop, count, curr);
        puts(oTop - output < n ? output : input);
    }
    return 0;
}