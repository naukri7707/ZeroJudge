#include <stdio.h>

int stack[100001];

int main()
{
    int n, sTop;
    char cmd;
    while (scanf(" %d", &n) == 1)
    {
        sTop = 0;
        while (n--)
        {
            scanf(" %c", &cmd);
            if (cmd == '1')
                sTop--;
            else if (cmd == '2')
                printf("%d\n", stack[sTop]);
            else
                scanf(" %d", &stack[++sTop]);
        }
    }
    return 0;
}