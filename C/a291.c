#include <stdio.h>

int n;
char ans[4], test[4];

int main()
{
    while (scanf(" %d %d %d %d %d", &ans[0], &ans[1], &ans[2], &ans[3], &n) == 5)
    {
        while (n--)
        {
            char ansCount[10] = { 0 }, testCount[10] = { 0 }, a = 0, b = 0;
            scanf(" %d %d %d %d", &test[0], &test[1], &test[2], &test[3]);
            for (int i = 0; i < 4; i++)
            {
                if (test[i] == ans[i])
                    a++;
                else
                {
                    if (ansCount[test[i]])
                        b++, ansCount[test[i]]--;
                    else
                        testCount[test[i]]++;
                    //
                    if (testCount[ans[i]])
                        b++, testCount[ans[i]]--;
                    else
                        ansCount[ans[i]]++;
                }
            }
            printf("%dA%dB\n", a, b);
        }
    }
    return 0;
}