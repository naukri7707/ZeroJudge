#include <stdio.h>

inline long long Gbit(long long src)
{
    return (src << 33) - (src << 29) - (src << 25) - (src << 24) - (src << 21)
        - (src << 19) - (src << 16) - (src << 15) - (src << 13) - (src << 12);
}

inline long long Mbit(long long src)
{
    return (src << 23) - (src << 18) - (src << 17) + (src << 12) + (src << 9);
}

inline int Kbit(int src)
{
    return (src << 13) - (src << 7) - (src << 6);
}

inline int Bit(int src)
{
    return src << 3;
}

int main()
{
    long long bits;
    int tmp;
    char str[1000];
    while (scanf(" %s", &str) == 1)
    {
        int tmp = bits = 0;
        for (int i = 0; str[i] != 0; i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                tmp = (tmp << 3) + (tmp << 1) + (str[i] - '0');
            }
            else
            {
                switch (str[i])
                {
                case 'g':
                    bits += Gbit(tmp), tmp = 0;
                    break;
                case 'm':
                    bits += Mbit(tmp), tmp = 0;
                    break;
                case 'k':
                    bits += Kbit(tmp), tmp = 0;
                    break;
                case 'y':
                    bits += Bit(tmp), tmp = 0;
                case 'i':
                    bits += tmp, tmp = 0;
                    break;
                case '.':
                    if (str[i + 2] == 'k')
                        bits += Kbit(tmp) + Bit((str[i + 1] - '0') * 100);
                    else
                        bits += Bit(tmp) + (str[i + 1] - '0');
                    i += 3, tmp = 0;
                    break;
                default:
                    break;
                }
            }
        }
        printf("%lld\n", bits);
    }
    return 0;
}