#include <stdio.h>

char input[10010];

int main()
{
    int sum;
    while (scanf(" %s", input) == 1)
    {
        sum = 0;
        for (int i = 0; input[i]; i++)
            sum += input[i] - '0';
        puts(sum % 3 ? "no" : "yes");
    }
    return 0;
}