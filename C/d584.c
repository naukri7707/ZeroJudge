#include<stdio.h>

int main()
{
    int occ, lv, ans;
    while (scanf(" %d %d", &occ, &lv) == 2)
    {
        if (occ == 0)
            ans = 0;
        else if (occ == 2)
        {
            ans = (lv - 8) * 3;
            if (lv >= 120)
                ans = ans + 6;
            else if (lv >= 70)
                ans = ans + 3;
            else if (lv >= 30)
                ans = ans + 2;
            else if (lv >= 8)
                ans = ans + 1;
        }
        else
        {
            ans = (lv - 10) * 3;
            if (lv >= 120)
                ans = ans + 6;
            else if (lv >= 70)
                ans = ans + 3;
            else if (lv >= 30)
                ans = ans + 2;
            else if (lv >= 10)
                ans = ans + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}