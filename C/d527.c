#include <stdio.h>
#define Color 0
#define Nation 1
#define Drink 2
#define Cigar 3
#define Pet 4

int house[7][5], isUse[7][5];

char dfs(int obj)
{
    if (obj == 1)
    {
        for (int i = 1; i <= 5; i++)
        {
            if ((house[i][Color] == 2 && house[i + 1][Color] != 3))
                return 0;
        }
    }
    if (obj == 2)
    {
        for (int i = 1; i <= 5; i++)
        {
            if ((house[1][Nation] != 9) || (house[i][Nation] == 6 && house[i][Color] != 1) ||
                (house[i][Nation] == 9 && !(house[i - 1][Color] == 5 || house[i + 1][Color] == 5)))
                return 0;
        }
    }
    else if (obj == 3)
    {
        for (int i = 1; i <= 5; i++)
        {
            if ((house[3][Drink] != 13) || (house[i][Nation] == 8 && house[i][Drink] != 11) ||
                (house[i][Color] == 2 && house[i][Drink] != 12))
                return 0;
        }
    }
    else if (obj == 4)
    {
        for (int i = 1; i <= 5; i++)
        {
            if ((house[i][Color] == 4 && house[i][Cigar] != 20) || (house[i][Cigar] == 18 && house[i][Drink] != 14) ||
                (house[i][Nation] == 10 && house[i][Cigar] != 19) || (house[i][Cigar] == 17 && !(house[i - 1][Drink] == 15 || house[i + 1][Drink] == 15)))
                return 0;
        }
    }
    else if (obj == 5)
    {
        for (int i = 1; i <= 5; i++)
        {
            if ((house[i][Nation] == 7 && house[i][Pet] != 21) || (house[i][Cigar] == 16 && house[i][Pet] != 22) ||
                (house[i][Cigar] == 17 && !(house[i - 1][Pet] == 23 || house[i + 1][Pet] == 23)) ||
                (house[i][Pet] == 24 && !(house[i - 1][Cigar] == 20 || house[i + 1][Cigar] == 20)))
                return 0;
        }
        return 1;
    }
    const int ft = obj * 5;
    char isUse[7] = { 0 };
    for (int t1 = 1; t1 <= 5; t1++)
    {
        house[1][obj] = ft + t1;
        isUse[t1] = 1;
        for (int t2 = 1; t2 <= 5; t2++)
        {
            if (isUse[t2]) continue;
            house[2][obj] = ft + t2;
            isUse[t2] = 1;
            for (int t3 = 1; t3 <= 5; t3++)
            {
                if (isUse[t3]) continue;
                house[3][obj] = ft + t3;
                isUse[t3] = 1;
                for (int t4 = 1; t4 <= 5; t4++)
                {
                    if (isUse[t4]) continue;
                    house[4][obj] = ft + t4;
                    isUse[t4] = 1;
                    for (int t5 = 1; t5 <= 5; t5++)
                    {
                        if (isUse[t5]) continue;
                        house[5][obj] = ft + t5;
                        if (dfs(obj + 1))
                            return 1;
                        break;
                    }
                    isUse[t4] = 0;
                }
                isUse[t3] = 0;
            }
            isUse[t2] = 0;
        }
        isUse[t1] = 0;
    }
    return 0;
}

int main()
{
    dfs(0);
    printf("     House     Color    Nation     Drink Cigarette       Pet\n");
    printf("        H1% 10d% 10d% 10d% 10d% 10d\n", house[1][0], house[1][1], house[1][2], house[1][3], house[1][4]);
    printf("        H2% 10d% 10d% 10d% 10d% 10d\n", house[2][0], house[2][1], house[2][2], house[2][3], house[2][4]);
    printf("        H3% 10d% 10d% 10d% 10d% 10d\n", house[3][0], house[3][1], house[3][2], house[3][3], house[3][4]);
    printf("        H4% 10d% 10d% 10d% 10d% 10d\n", house[4][0], house[4][1], house[4][2], house[4][3], house[4][4]);
    printf("        H5% 10d% 10d% 10d% 10d% 10d\n", house[5][0], house[5][1], house[5][2], house[5][3], house[5][4]);
    return 0;
}