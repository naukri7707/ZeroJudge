#include <stdio.h>

int sum, eng[26] = { 10 ,11 ,12 ,13 ,14 ,15 ,16 ,17 ,34 ,18 ,19 ,20 ,21
                    ,22 ,35 ,23 ,24 ,25 ,26 ,27 ,28 ,29 ,32 ,30 ,31 ,33 };
char input[11];

int main()
{
    for (int i = 0; i < 26; i++)
        eng[i] = eng[i] / 10 + (eng[i] % 10) * 9;
    while (scanf(" %s", input) == 1)
    {
        sum = (input[7] - '0') + (input[8] - '0');
        for (int i = 0; i < 7; i++)
            sum += (input[i] - '0') * (8 - i);
        for (int i = 0; i < 26; i++)
        {
            if (!((sum + eng[i]) % 10))
                putchar('A' + i);
        }
        putchar('\n');
    }
    return 0;
}