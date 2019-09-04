#include <stdio.h>
#include <memory.h>

char list[64][7], * map[256];

void setList(char list[][7], char* map[])
{
    register char* now = list;
    char tmp[5];
    for (int i = '0'; i <= '1'; i++)
    {
        tmp[0] = i;
        for (int j = '0'; j <= '1'; j++)
        {
            tmp[1] = j;
            for (int k = '0'; k <= '1'; k++)
            {
                tmp[2] = k;
                for (int l = '0'; l <= '1'; l++)
                {
                    tmp[3] = l;
                    for (int m = '0'; m <= '1'; m++)
                    {
                        tmp[4] = m;
                        memcpy(now, tmp, 5);
                        now[5] = '0', now += 7;
                        memcpy(now, tmp, 5);
                        now[5] = '1', now += 7;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 26; i++)
        map['A' + i] = list[i];
    for (int i = 0; i < 26; i++)
        map['a' + i] = list[26 + i];
    for (int i = 0; i < 10; i++)
        map['0' + i] = list[52 + i];
    map['+'] = list[62];
    map['/'] = list[63];
}

int main()
{
    int n;
    char input[210];
    setList(list, map);
    scanf(" %d %*d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        gets(input);
        for (int j = 0; input[j]; j++)
            fputs(map[input[j]], stdout);
        putchar('\n');
    }
    return 0;
}