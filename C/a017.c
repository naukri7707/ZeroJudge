#include <stdio.h>
#define MAX 10000

long long stack[MAX];
char infix[MAX], postfix[MAX], pTop;

char priority(char op)
{
    switch (op)
    {
    case '*': case '/': case '%':
        return 2;
    case '+': case '-':
        return 1;
    default:
        return 0;
    }
}

void inToPostfix(char* infix, char* postfix)
{
    int sTop = 0;
    char stack[MAX] = { 0 };
    pTop = 0;
    for (int i = 0; infix[i]; i++)
    {
        switch (infix[i])
        {
        case ' ':
            break;
        case '(':
            stack[++sTop] = infix[i];
            break;
        case ')':
            while (stack[sTop] != '(')
            {
                postfix[pTop++] = stack[sTop--];
            }
            sTop--;
            break;
        case '+': case '-': case '*': case '/': case '%':
            while (priority(infix[i]) <= priority(stack[sTop]))
            {
                postfix[pTop++] = stack[sTop--];
            }
            stack[++sTop] = infix[i];
            break;
        default:
            do
            {
                postfix[pTop++] = infix[i++];
            } while (infix[i] >= '0' && infix[i] <= '9');
            postfix[pTop++] = ' ';
            i--;
        }
    }
    while (sTop)
    {
        postfix[pTop++] = stack[sTop--];
    }
    postfix[pTop++] = '\0';
}

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
    stack[0] = 0;
    int sTop = 0;
    char* now = postfix - 1;
    for (int i = 0; postfix[i]; i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            stack[sTop] = stack[sTop] * 10 + (postfix[i] - '0');
        }
        else if (postfix[i] == ' ')
        {
            sTop++;
        }
        else
        {
            sTop--;
            stack[sTop - 1] = cale(stack[sTop - 1], stack[sTop], postfix[i]);
            stack[sTop] = 0;
        }
    }
    return stack[0];
}


int main()
{
    while (gets(infix) != NULL)
    {
        inToPostfix(infix, postfix);
        printf("%lld\n", postfixToInt(postfix));
    }
    return 0;
}