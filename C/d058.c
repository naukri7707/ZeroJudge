#include <stdio.h>

int main()
{
    int n;
    scanf(" %d", &n);
    printf("%d\n", n > 0 ? 1 : n < 0 ? -1 : 0);
    return 0;
}