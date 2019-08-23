#include <stdio.h>
#include <stdlib.h>
#define MAX 1048576

int t, n, list[50];
char s[MAX + 10], isTriangle;

int cmp(const int* lhs, const int* rhs)
{
    return *lhs - *rhs;
}

int main()
{
    while (scanf(" %d", &t) == 1)
    {
        while (t--)
        {
            scanf(" %d", &n);
            if (n > 44)
            {
                getchar();
                do
                {
                    s[MAX - 2] = -1;
                } while (fgets(s, MAX, stdin)[MAX - 2] != EOF);
                puts("YES");
            }
            else
            {
                isTriangle = 0;
                for (int i = 0; i < n; i++)
                    scanf(" %d", &list[i]);
                qsort(list, n, sizeof(int), cmp);
                for (int i = 2; i < n; i++)
                {
                    if (list[i - 2] + list[i - 1] > list[i])
                    {
                        isTriangle = 1;
                        break;
                    }
                }
                puts(isTriangle ? "YES" : "NO");
            }
        }
    }
    return 0;
}