#include <stdio.h>

int n;
char out[35], * ans;
int main()
{
    while (scanf(" %d", &n) == 1)
    {
        ans = &out[34];
        while (n)
        {
            *ans-- = (n & 1) + '0';
            n >>= 1;
        }
        puts(++ans);
    }
    return 0;
}