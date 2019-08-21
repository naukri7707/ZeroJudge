#include <stdio.h>
#include <string.h>

char rowKill[][30] = { "", "You have slain an enemie.", "You have slain an enemie.", "KILLING SPREE!",
                 "RAMPAGE~", "UNSTOPPABLE!", "DOMINATING!", "GUALIKE!", "LEGENDARY!" }, str[15];

int main()
{
    int n, act, k, d, a, rk;
    while (scanf(" %d", &n) == 1)
    {
        k = d = a = rk = 0;
        for (int i = 0; i < n; i++)
        {
            scanf(" %s", str);
            act = strlen(str);
            if (act == 8)
            {
                k++, rk++;
                puts(rowKill[rk < 8 ? rk : 8]);
            }
            else if (act == 10)
            {
                a++;
            }
            else
            {
                puts(rk < 3 ? "You have been slained." : "SHUTDOWN.");
                d++, rk = 0;
            }
        }
        printf("%d/%d/%d\n", k, d, a);
    }
    return 0;
}