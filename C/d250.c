#include <stdio.h>

int main()
{
    int ans;
    char input[10], output[2] = { 0 };
    while (gets(input))
    {
        ans = 45;
        for (int i = 0; i < 9; i++)
            ans -= input[i] ^ '0';
        output[0] = ans | '0';
        puts(output);
    }
    return 0;
}