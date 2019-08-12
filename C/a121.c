#include <stdio.h>

int n, m;

int main()
{
    while (scanf("%d %d", &n, &m) == 2)
    {
        int num = 0, i = n;
        for (; i < 2 && i <= m; i++)
            ;
        for (; i <= m; i++)
        {
            num++;
            for (int j = 2; j * j <= i; j++)
            {
                if (i % j == 0)
                {
                    num--;
                    break;
                }
            }
        }
        printf("%d\n", num);
    }
    return 0;
}