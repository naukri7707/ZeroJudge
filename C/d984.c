#include <stdio.h>

int main()
{
    long long a, b, c;
    while (scanf(" %lld %lld %lld", &a, &b, &c) == 3)
    {
        if (a > b && a > c)
        {
            if (a > b + c)puts("A");
            else if (b > c)puts("B");
            else puts("C");
        }
        else if (b > a && b > c)
        {
            if (b > a + c)puts("B");
            else if (a > c)puts("A");
            else puts("C");
        }
        else
        {
            if (c > a + b)puts("C");
            else if (a > b)puts("A");
            else puts("B");
        }
    }
    return 0;
}