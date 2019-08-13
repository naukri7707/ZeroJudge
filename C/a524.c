#include <stdio.h>

int n;
char unUse[10] = "012345678", output[10];

void dfs(int now, char* oTop)
{
    if (now == n)
    {
        puts(output);
        return;
    }
    for (int i = n; i; i--)
    {
        if (unUse[i])
        {
            *oTop = unUse[i] , unUse[i] = 0;
            dfs(now + 1 , oTop + 1);
            unUse[i] = *oTop;
        }
    }
}

int main()
{
    while (scanf("%d", &n) == 1)
    {
        output[n] = '\0';
        dfs(0, output);
    }
    return 0;
}