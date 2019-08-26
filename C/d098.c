#include <stdio.h>
#include <string.h>

int sum;
char input[1000], * tok;

inline int getInt(char src[])
{
    int res = 0;
    for (int i = 0; src[i]; i++)
    {
        if (src[i] >= '0' && src[i] <= '9')
            res = (res << 3) + (res << 1) + (src[i] - '0');
        else
            return 0;
    }
    return res;
}

int main()
{
    while (gets(input) != NULL)
    {
        sum = 0, tok = strtok(input, " ");
        while (tok != NULL)
        {
            sum += getInt(tok);
            tok = strtok(NULL, " ");
        }
        printf("%d\n", sum);
    }
    return 0;
}
