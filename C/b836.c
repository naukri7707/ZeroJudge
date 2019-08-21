#include <stdio.h>

int main()
{
    int n, m;
    unsigned int c;
    while (scanf(" %d %d", &n, &m) == 2)
    {
        c = 1;
        if (!m)
            n = 0;
        while (n > 0)
        {
            n -= c;
            c += m;
        }
        puts(n ? "No Stop!!" : "Go Kevin!!");
    }
    return 0;
}