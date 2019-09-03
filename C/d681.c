#include <stdio.h>

int ans, tmp;
char input[1100], output[1100], * iTop, * oTop;

void getBin(int* src)
{
    *src = 0;
    for (int i = 4; ~i; i--)
    {
        *src += ((*iTop - '0') << i);
        *oTop++ = *iTop++;
    }
}

int main()
{
    while (gets(input))
    {
        iTop = input, oTop = output, getBin(&ans);
        for (;;)
        {
            if (iTop[1] == 'o')
            {
                iTop += 4;
                *oTop++ = '|', * oTop++ = '|';
                getBin(&tmp);
                ans |= tmp;
            }
            else if (iTop[1] == 'a')
            {
                iTop += 5;
                *oTop++ = '&', * oTop++ = '&';
                getBin(&tmp);
                ans &= tmp;
            }
            else break;
        }
        *oTop++ = ' ', * oTop++ = '=', * oTop++ = ' ';
        for (int i = 0; i < 5; i++)
            * oTop++ = ((ans >> (4 - i)) & 1) + '0';
        *oTop = '\0';
        puts(output);
    }
    return 0;
}