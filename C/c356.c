#include <stdio.h>
#define MAX 5005

char s[MAX], ans[MAX];

int main()
{
    int n, np;
    scanf(" %d", &n);
    getchar();
    np = n + 2;
    for (int i = 0; i < n; i++)
    {
        fgets(s, np, stdin);
        ans[i] = s[0];
    }
    ans[n] = 0;
    puts(ans);
    return 0;
}