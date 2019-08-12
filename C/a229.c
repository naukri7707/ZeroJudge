#include <stdio.h>

int n, max;
char paren[30];

void dfs(int open, int close, int now)
{
    if (open > n || open < close)
        return;
    if (now == max)
    {
        puts(paren);
        return;
    }
    paren[now] = '(', dfs(open + 1, close, now + 1);
    paren[now] = ')', dfs(open, close + 1, now + 1);
}

int main()
{
    while (scanf(" %d", &n) == 1)
    {
        max = n << 1;
        dfs(0, 0, 0);
        putchar('\n');
    }
    return 0;
}