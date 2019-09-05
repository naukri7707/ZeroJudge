#include <stdio.h>

int main()
{
    double w, h;
    scanf(" %lf %lf", &w, &h);
    printf("%.1lf", (w * 10000) / (h * h));
    return 0;
}