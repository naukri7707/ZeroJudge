#include <stdio.h>

int row = 0, col = 0 , matrix[100][100];

int main()
{
    while (scanf(" %d %d", &row, &col) == 2)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
                scanf(" %d", &matrix[j][i]);
        }
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
                printf("%d ", matrix[i][j]); // 反轉
            putchar('\n');
        }
    }
    return 0;
}