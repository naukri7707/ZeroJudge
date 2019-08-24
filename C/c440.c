#include <stdio.h>

char input[100010];

int main()
{
    long long ans = 0;
    int sumQ = 0, leftQ = 0;
    gets(input);
    for (int i = 0; input[i]; i++)
    {
        if (input[i] == 'Q')
            sumQ++, ans += leftQ;
        else if (input[i] == 'A')
            leftQ += sumQ;
    }
    printf("%lld", ans);
    return 0;
}