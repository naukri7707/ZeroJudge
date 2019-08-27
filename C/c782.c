#pragma GCC optimize(3)
#include <stdio.h>
#define MAX 2000010
#define BUFMAX 1048576

long long sum, w[MAX];
int kase, n, k, length = BUFMAX, a[MAX], v[MAX];
char buf[BUFMAX], tmp, * pt = buf, * end = buf;

inline char freadChar()
{
    if (pt == end)
    {
        if (length < BUFMAX)
            return EOF;
        length = fread(buf, 1, BUFMAX, stdin);
        end = buf + length;
        pt = buf;
    }
    return *pt++;
}

inline void freadUInt(int* val)
{
    while ((tmp = freadChar()) < '0')
        if (tmp == EOF) return;
    *val = tmp - '0';
    while ((tmp = freadChar()) >= '0')
        * val = (*val << 3) + (*val << 1) + (tmp - '0');
}

inline void freadLongLong(long long* val)
{
    while ((tmp = freadChar()) < '-')
        if (tmp == EOF) return;
    if (tmp == '-')
    {
        *val = freadChar() - '0';
        while ((tmp = freadChar()) >= '0')
            * val = (*val << 3) + (*val << 1) + (tmp - '0');
        *val = -*val;
    }
    else
    {
        *val = tmp - '0';
        while ((tmp = freadChar()) >= '0')
            * val = (*val << 3) + (*val << 1) + (tmp - '0');
    }
}

int main()
{
    scanf(" %d", &kase);
    while (kase--)
    {
        sum = 0;
        freadUInt(&n), freadUInt(&k);
        for (int i = 1; i <= n; i++)
            freadUInt(&a[i]);
        for (int i = 1, s = 1; i <= n; i++)
        {
            while (a[i] - a[s] > k)
                s++;
            v[i] = s - 1;
        }
        for (int i = 1; i <= n; i++)
        {
            freadLongLong(&w[i]);
            sum += w[v[i]] * w[i];
            w[i] += w[i - 1];
        }
        printf("%lld\n", sum);
    }
    return 0;
}