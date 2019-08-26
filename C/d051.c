#include <stdio.h>

int main()
{
    int n;
    scanf(" %d", &n);
    printf("%.3lf\n", (double)(n - 32) / 1.8);
    return 0;
}