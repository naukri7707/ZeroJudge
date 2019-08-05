#include <stdio.h>

int sum, eng[26] = { 10 ,11 ,12 ,13 ,14 ,15 ,16 ,17 ,34 ,18 ,19 ,20 ,21
                                ,22 ,35 ,23 ,24 ,25 ,26 ,27 ,28 ,29 ,32 ,30 ,31 ,33 };
char input[11];

int main()
{
    while (gets(input) != NULL)
    {
        sum = eng[input[0] - 'A'] / 10 + (eng[input[0] - 'A'] % 10) * 9
            + (input[8] - '0') + (input[9] - '0');
        for (int i = 1; i < 8; i++)
            sum += (input[i] - '0') * (9 - i);
        if (sum % 10 == 0)puts("real");
        else puts("fake");
    }
    return 0;
}