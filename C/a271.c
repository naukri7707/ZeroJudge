#include <stdio.h>

int kase, x, y, z, w, n, m, nt, r;
char buffer[1000], * curr;

inline char* sgetInt(char* src, int* dst)
{
    *dst = 0;
    int i = 0, getNum = 0;
    for (; src[i]; i++)
    {
        if (src[i] >= '0' && src[i] <= '9')
            * dst = (*dst << 3) + (*dst << 1) + (src[i] - '0'), getNum = 1;
        else if (getNum)
            return src + i + 1;
    }
    return getNum ? src + i : NULL;
}

int main()
{
    scanf("%d", &kase);
    getchar();
    while (kase--)
    {
        gets(buffer), curr = buffer;
        curr = sgetInt(curr, &x), curr = sgetInt(curr, &y), curr = sgetInt(curr, &z);
        curr = sgetInt(curr, &w), curr = sgetInt(curr, &n), curr = sgetInt(curr, &m);
        gets(buffer), curr = buffer, nt = 0;
        while ((curr = sgetInt(curr, &r)) != NULL)
        {
            if ((m -= nt) <= 0)
                break;
            switch (r)
            {
            case 1:
                m += x;
                break;
            case 2:
                m += y;
                break;
            case 3:
                m -= z;
                break;
            case 4:
                m -= w, nt += n;
                break;
            default:
                break;
            }
        }
        m > 0 ? printf("%dg\n", m) : puts("bye~Rabbit");
    }
    return 0;
}