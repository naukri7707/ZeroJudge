#include <stdio.h>

int main()
{
    int a, b;
    char s;
    while (scanf(" %d %c %d", &a, &s, &b) == 3)
    {
        switch (s)
        {
        case '+':
            printf("%d\n", a + b);
            break;
        case '-':
            printf("%d\n", a - b);
            break;
        case '*':
            printf("%d\n", a * b);
            break;
        default:
            printf("%d\n", a / b);
            break;
        }
    }
    return 0;
}