#include <stdio.h>
#define MAX 10000

long long stack[MAX];
int sTop;
char postfix[MAX];

long long cale(long long lhs, long long rhs, char op)
{
    switch (op)
    {
    case '+': return lhs + rhs;
    case '-': return lhs - rhs;
    case '*': return lhs * rhs;
    case '/': return lhs / rhs;
    case '%': return lhs % rhs;
    }
    return -1;
}

long long postfixToInt(char* postfix)
{
    stack[0] = sTop = 0;
    char* now = postfix - 1;
    for (int i = 0; postfix[i]; i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
            stack[sTop] = (stack[sTop] << 3) + (stack[sTop] << 1) + (postfix[i] - '0');
        else if (postfix[i] == ' ')
            sTop++;
        else
        {
            sTop -= 2;
            stack[sTop] = cale(stack[sTop], stack[sTop + 1], postfix[i]);
            stack[sTop + 1] = 0;
        }
    }
    return stack[0];
}

int main()
{
    while (gets(postfix) != NULL)
    {
        printf("%lld\n", postfixToInt(postfix));
    }
    return 0;
}