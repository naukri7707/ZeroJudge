#include <stdio.h>

const char n2e[] = "mjqhofawcpnsexdkvgtzblryui", e2n[] = "uzrmatifxopnhwvbslekycqjgd";
const char* e2e[] = { e2n + 4, e2n + 15, e2n + 21, e2n + 25, e2n + 18, e2n + 7, e2n + 24, e2n + 12,
            e2n + 6, e2n + 23, e2n + 19, e2n + 17, e2n + 3, e2n + 11, e2n + 9, e2n + 10, e2n + 22,
            e2n + 2, e2n + 16, e2n + 5, e2n + 0, e2n + 14, e2n + 13, e2n + 8, e2n + 20, e2n + 1 };
char input[30030], output[10010];

inline char* getUInt(char buffer[], unsigned int* dst)
{
    while (*buffer < '0')
        if (!*buffer++) return NULL;
    *dst = *buffer ^ '0';
    while (*++buffer >= '0')
        * dst = (*dst << 3) + (*dst << 1) + (*buffer ^ '0');
    return buffer;
}

int main()
{
    int n, m, tmp, sum;
    char* st, * oTop;
    scanf(" %d", &n);
    getchar();
    while (n--)
    {
        sum = 0;
        gets(input);
        st = getUInt(input, &m) + 1;
        if (st[0] < 'a')
        {
            oTop = output;
            for (int i = 0; i < m; i++)
                st = getUInt(st, &tmp), * oTop++ = n2e[tmp - 1];
            *oTop = '\0';
        }
        else
        {
            for (int i = 0; i < m; i++)
                sum += e2e[*st - 'a'] - e2n + 1, st += 2;
        }
        sum ? printf("%d\n", sum) : puts(output);
    }
    return 0;
}