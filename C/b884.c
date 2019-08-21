#include <stdio.h>

int main()
{
    int n, x, y, yee;
    scanf(" %d", &n);
    while (n--)
    {
        scanf(" %d %d", &x, &y);
        yee = 100 - x - y;
        if (yee <= 0) puts("evil!!");
        else if (yee <= 30) puts("sad!");
        else if (yee <= 60) puts("hmm~~");
        else if (yee < 100) puts("Happyyummy");
        else puts("evil!!");
    }
    return 0;
}