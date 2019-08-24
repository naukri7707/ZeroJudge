#include <stdio.h>
#include <string.h>

char list[60000010], ans[101], * input;

int main()
{
    int n, m, tmp;
    while (scanf(" %d %d", &n, &m) == 2 && n + m)
    {
        getchar();
        input = list;
        int length = 0;
        for (int i = 0; i < n; i++)
        {
            gets(input);
            input += strlen(input);
        }
        for (int i = 0; i < m; i++)
        {
            scanf(" %d", &tmp);
            ans[i] = list[tmp - 1];
        }
        ans[m] = 0;
        puts(ans);
    }
    return 0;
}