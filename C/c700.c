#include <stdio.h>

int s1Len, s2Len;
char cmd[20], output[200000], * oTop = output;

int main()
{
    while (gets(cmd) != NULL)
    {
        if (cmd[1] == 'u')
        {
            s1Len++;
            *oTop++ = '1';
        }
        else if (s2Len)
        {
            *oTop++ = '4';
            s2Len--;
        }
        else
        {
            s2Len = s1Len - 1;
            while (--s1Len)
                * oTop++ = '5';
            *oTop++ = '5', * oTop++ = '4';
        }
    }
    puts(output);
    return 0;
}