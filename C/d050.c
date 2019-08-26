#include<stdio.h>

int main()
{
    int n;
    scanf(" %d", &n);
    printf("%d", n >= 15 ? n - 15 : n + 9);
    return 0;
}