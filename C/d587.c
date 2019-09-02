#include <stdio.h>

int list[4];
char outstr[4][3] = { "", "1 ", "2 " , "3 " };

int main()
{
    int n, tmp;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %d", &tmp);
        list[tmp]++;
    }
    for (int i = 1; i <= 3; i++)
    {
        while (list[i]--)
            fputs(outstr[i], stdout);
    }
    return 0;
}