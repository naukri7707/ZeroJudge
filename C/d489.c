#include <stdio.h>

int main()
{
    int a, b, c, s;
    scanf(" %d %d %d", &a, &b, &c);
    s = (a + b + c) / 2;
    printf("%d\n", s * (s - a) * (s - b) * (s - c));
    return 0;
}