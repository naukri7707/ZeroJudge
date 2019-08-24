#include <stdio.h>

int ans;
char list[11];

int main()
{
    while (scanf(" %s", &list) == 1)
    {
        ans = 0;
        for (int i = 0; list[i]; i++)
        {
            if (list[i] == '0') ans++;
            else if (list[i] == '6') ans++;
            else if (list[i] == '8') ans += 2;
            else if (list[i] == '9') ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}