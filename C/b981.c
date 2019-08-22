#include <stdio.h>

int main()
{
    int tmp, time;
    char str[1000];
    while (scanf(" %s", str) == 1)
    {
        time = tmp = 0;
        for (int i = 0; str[i] != 0; i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                tmp = tmp * 10 + (str[i] - '0');
            }
            else
            {
                switch (str[i])
                {
                case 'h':
                    time += tmp * 3600000;
                    if (str[i + 1] == 'o')
                        i += 4;
                    break;
                case 'm':
                    if (str[i + 1] == 's')
                        time += tmp, i += 2;
                    else
                        time += tmp * 60000;
                    break;
                case 's':
                    time += tmp * 1000;
                    break;
                case '.':
                    time += tmp * 1000 + (str[i + 1] - '0') * 100, i += 2;
                    break;
                default:
                    break;
                }
                tmp = 0;
            }
        }
        printf("%d\n", time);
    }
    return 0;
}