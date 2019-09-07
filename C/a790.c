#include <stdio.h>
#define MAX 110

int dp[MAX][MAX], row, col, len, sX, sY;
char map[MAX][MAX], * st;

char* strchr(const char ch)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (map[i][j] == ch)
                return &map[i][j];
        }
    }
    return NULL;
}

int main()
{
    while (scanf(" %d %d %d", &col, &row, &len) == 3)
    {
        getchar();
        for (int i = 0; i < row; i++)
        {
            gets(map[i]);
            for (int j = 0; j < col; j++)
                dp[i][j] = 0;
        }
        st = strchr('S');
        sX = (st - &map[0][0]) / MAX, sY = (st - &map[0][0]) % MAX;
        map[sX][sY] = '.', dp[sX][sY] = len - 1;
        while (--len)
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if (dp[i][j] == len)
                    {
                        if (i + 1 < row && map[i + 1][j] != '#')
                            map[i + 1][j] = '.', dp[i + 1][j] = len - 1;
                        if (i - 1 >= 0 && map[i - 1][j] != '#')
                            map[i - 1][j] = '.', dp[i - 1][j] = len - 1;
                        if (j + 1 < col && map[i][j + 1] != '#')
                            map[i][j + 1] = '.', dp[i][j + 1] = len - 1;
                        if (j - 1 >= 0 && map[i][j - 1] != '#')
                            map[i][j - 1] = '.', dp[i][j - 1] = len - 1;
                    }
                }
            }
        }
        for (int i = 0; i < row; i++)
            puts(map[i]);
        if (!strchr('F'))
            puts("All Fires Extinguished!");
    }
    return 0;
}