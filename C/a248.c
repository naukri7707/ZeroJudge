#include<stdio.h>

int a, b, n;
char output[10010], * oTop;

int main()
{
    while (scanf(" %d %d %d", &a, &b, &n) == 3)
    {
        oTop = output;
        printf("%d.", a / b);
        while (n--)
        {
            a %= b;
            a = (a << 3) + (a << 1);
            *oTop++ = (a / b) + '0';
        }
        *oTop = '\0';
        puts(output);
    }
    return 0;
}