#include <stdio.h>
#define MAX 100

int main()
{
    int kase, n, tmp, p2List[110], count;
    for (int i = 2; i <= MAX; i++)
        p2List[i] = i * i;
    scanf(" %d", &kase);
    while (kase--)
    {
        count = 0;
        int list[MAX + 1] = { 0 };
        scanf(" %d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf(" %d", &tmp);
            list[tmp]++;
        }
        for (int i = MAX; i > 2; i--)
        {
            if (!list[i]) continue;
            for (int j = i - 1; j > 1; j--)
            {
                if (!list[j]) continue;
                for (int k = j - 1; k; k--)
                {
                    if (list[k] && p2List[i] == p2List[j] + p2List[k])
                        count += list[i] * list[j] * list[k];
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}