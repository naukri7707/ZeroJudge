#include <stdio.h>

int main()
{
    double a, b, c, d, det;
    while (scanf("%lf %lf %lf %lf", &a, &b, &c, &d) == 4 && a + b + c + d)
    {
        det = a * d - b * c;
        if (det)
            printf("%.5lf %.5lf\n%.5lf %.5lf\n", d / det, -b / det, -c / det, a / det);
        else
            puts("cheat!");
    }
    return 0;
}