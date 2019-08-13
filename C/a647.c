#include <stdio.h>
#define EPS 0.00001
#define EPS2 0.0001

int main()
{
    int n, m, p;
    double gap;
    while (scanf(" %d", &n) == 1)
    {
        for (int i = 0; i < n; i++)
        {
            scanf(" %d %d", &m, &p);
            gap = (double)((p - m) * 100) / m;
            gap += gap < 0 ? -EPS : EPS;
            if (gap < EPS2 && gap > -EPS2)
                gap = 0;
            printf("%.2lf%% %s\n", gap, gap < 10 && gap > -7 ? "keep" : "dispose");
        }
    }
    return 0;
}