#include <stdio.h>

int main()
{
    int  n, x, y, a, b;
    while (scanf(" %d", &n) == 1)
    {
        x = y = 0;
        for (int i = 0; i < n; i++)
        {
            scanf(" %d %d", &a, &b);
            switch (a)
            {
            case 0:
                y += b;
                break;
            case 1:
                x += b;
                break;
            case 2:
                y -= b;
                break;
            default:
                x -= b;
                break;
            }
        }
        printf("%d %d\n", x, y);
    }
    return 0;
}