#include <stdio.h>

int main()
{
    int n;
    char ans[5], test[5];
    while (scanf(" %s %d", ans, &n) == 2)
    {
        for (int i = 0; i < 4; i++)
            ans[i] -= '0';
        while (n--)
        {
            char ansCount[10] = { 0 }, testCount[10] = { 0 }, a = 0, b = 0;
            scanf(" %s", test);
            for (int i = 0; i < 4; i++)
                test[i] -= '0';
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
