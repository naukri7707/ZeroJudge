#include <stdio.h>

char input[10000], curr, bestC;
int count, best;

int main()
{
    while (scanf(" %s", input) == 1)
    {
        count = best = 0;
        for (int i = 0; input[i]; i++)
        {
            if (input[i] == curr)
                count++;
            else
            {
                if (best < count)
                    best = count, bestC = curr;
                count = 1, curr = input[i];
            }
        }
        if (best < count)
            best = count, bestC = curr;
        printf("%c %d\n", bestC, best);
    }
    return 0;
}