#include <stdio.h>

int main()
{
    int n;
    scanf(" %d", &n);
    printf("%d", (n / 12) * 50 + (n % 12) * 5);
    return 0;
}