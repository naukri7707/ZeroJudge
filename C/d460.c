#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", (n >= 6 && n < 12) * 590 + (n >= 12 && n < 18) * 790
        + (n >= 18 && n < 60) * 890 + (n >= 60) * 399);
    return 0;
}