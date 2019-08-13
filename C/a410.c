#include<stdio.h>

double a, b, c, d, e, f, x, y;

int main()
{
    scanf(" %lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f);
    if (a * e == d * b)
        puts(b * f == e * c ? "Too many" : "No answer");
    else
        printf("x=%.2lf\ny=%.2lf\n", (c * e - b * f) / (a * e - d * b), (d * c - a * f) / (b * d - a * e));
    return 0;
}