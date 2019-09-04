#include <stdio.h>

char mult3(int src)
{
    int res = 0;
    do
    {
        res += src & 1;
        src >>= 1;
        res -= src & 1;
    } while (src >>= 1);
    if (res < 0)
        res = -res;
    return res == 0 || res == 3 || res == 9 || res == 12 || res == 15 ||
        res == 18 || res == 21 || res == 24 || res == 27 || res == 30;
}

int main()
{
    int n;
    while (scanf(" %d", &n) == 1)
    {
        puts(mult3(n) ? "YES" : "NO");
    }
    return 0;
}