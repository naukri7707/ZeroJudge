#include <stdio.h>
#include <string.h>

double num, sum;
int idx;
char input[10000], * tok;

int main()
{
    while (gets(input) != NULL)
    {
        sum = 0, tok = strtok(input, " ");
        while (tok != NULL)
        {
            sscanf(tok, "%d:%lf", &idx, &num);
            sum += idx & 1 ? num : -num;
            tok = strtok(NULL, " ");
        }
        printf("%g\n", sum);
    }
    return 0;
}