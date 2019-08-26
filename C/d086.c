#include <stdio.h>

const char a = 'a' - 1, A = 'A' - 1;
int score;
char input[200];

int main()
{
    while (scanf(" %s", input) == 1 && !(input[0] == '0' && input[1] == '\0'))
    {
        score = 0;
        for (int i = 0; input[i]; i++)
        {
            if (input[i] >= 'a' && input[i] <= 'z')
                score += input[i] - a;
            else if (input[i] >= 'A' && input[i] <= 'Z')
                score += input[i] - A;
            else
            {
                puts("Fail");
                score = 0;
                break;
            }
        }
        if (score)
            printf("%d\n", score);
    }
    return 0;
}