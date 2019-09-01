#include <stdio.h>

inline void putUInt(register unsigned int src, const char suffix)
{
    register unsigned int div;
    char buffer[12], * st = buffer + 10;
    *st = suffix, * (st + 1) = 0;
    do
    {
        *(--st) = src - ((div = src / 10) << 3) - (div << 1) + '0';
    } while (src = div);
    fputs(st, stdout);
}

int main()
{
    int n, list[100], s, e;
    while (scanf(" %d", &n) == 1)
    {
        for (int i = 0; i < n; i++)
            scanf(" %d", &list[i]);
        s = 0, e = n - 1;
        while (s <= e)
        {
            for (int i = s; i <= e; i++)
                putUInt(list[i], ' ');
            putchar('\n');
            s++;
            for (int i = e; i >= s; i--)
                putUInt(list[i], ' ');
            putchar('\n');
            e--; 
        }
    }
    return 0;
}