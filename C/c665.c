#include <stdio.h>

const char A = 'A' - 10;
int b1, b2, rem, sum;
char input[2000], * output;

int main()
{
    while (scanf("%s %d %d", input, &b1, &b2) == 3)
    {
        output = input + 999;
        sum = 0;
        for (int i = 0; input[i]; i++)
        {
            if (input[i] <= '9')
                sum = sum * b1 + (input[i] - '0');
            else
                sum = sum * b1 + (input[i] - A);
        }
        while (sum)
        {
            rem = sum % b2;
            *--output = rem <= 9 ? rem + '0' : rem + A;
            sum /= b2;
        }
        puts(output);
    }
    return 0;
}