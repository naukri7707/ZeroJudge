#pragma GCC optimize(3)
#include <stdio.h>
#include <memory.h>
#define BUFSIZ 1048576
#define MOD 10000000
#define MUTMOD(x) ((x<<24)-(x<<22)-(x<<21)-(x<<19)+(x<<16)-(x<<14)-(x<<13)-(x<<11)-(x<<8)-(x<<7))

typedef struct BigNum
{
    unsigned long long Num[72000];
    int Last;
}BigNum;

BigNum list[3], * n = &list[0], * ans = &list[1], * tmp = &list[2];
char output[500050];

inline char readChar()
{
    static char buffer[BUFSIZ], * now = buffer + BUFSIZ, * end = buffer + BUFSIZ;
    if (now == end)
    {
        if (end < buffer + BUFSIZ)
            return EOF;
        end = (buffer + fread(buffer, 1, BUFSIZ, stdin));
        now = buffer;
    }
    return *now++;
}

inline char readUInt(unsigned int* dst)
{
    register char ch;
    while ((ch = readChar()) < '0')
        if (ch == EOF) return 0;
    *dst = ch ^ '0';
    while ((ch = readChar()) >= '0')
        * dst = (*dst << 3) + (*dst << 1) + (ch ^ '0');
    return 1;
}

inline BigNum* BigMult(BigNum* dst, BigNum* times)
{
    memset(tmp, 0, sizeof(BigNum));
    tmp->Last = dst->Last + times->Last;
    register unsigned long long div;
    for (int i = 0; i <= dst->Last; i++)
    {
        if (dst->Num[i])
        {
            for (int j = 0; j <= times->Last; j++)
            {
                if (times->Num[j])
                    tmp->Num[i + j] += dst->Num[i] * times->Num[j];
            }
        }
    }
    for (int i = 0; i <= tmp->Last; i++)
    {
        if (tmp->Num[i] >= MOD)
        {
            div = tmp->Num[i] / MOD;
            tmp->Num[i] = tmp->Num[i] - MUTMOD(div);
            tmp->Num[i + 1] += div;
            if (tmp->Last < i + 1)
                tmp->Last = i + 1;
        }
    }
    BigNum* res = tmp;
    tmp = dst;
    return res;
}

void pow(BigNum* dst, BigNum* src, int m)
{
    dst->Num[0] = 1, dst->Last = 0;
    for (;; m >>= 1)
    {
        if (m & 1)
        {
            dst = BigMult(dst, src);
            if (m == 1)
                break;
        }
        src = BigMult(src, src);
    }
    ans = dst;
    n = src;
}

void putUBigNum(char buffer[], BigNum* src)
{
    register char* st = buffer;
    register unsigned long long div1, div2;
    for (int i = src->Last; ~i; i--, st += 7)
    {
        st[6] = (src->Num[i] - ((div1 = src->Num[i] / 10) << 3) - (div1 << 1)) | '0';
        st[5] = (div1 - ((div2 = div1 / 10) << 3) - (div2 << 1)) | '0';
        st[4] = (div2 - ((div1 = div2 / 10) << 3) - (div1 << 1)) | '0';
        st[3] = (div1 - ((div2 = div1 / 10) << 3) - (div2 << 1)) | '0';
        st[2] = (div2 - ((div1 = div2 / 10) << 3) - (div1 << 1)) | '0';
        st[1] = (div1 - ((div2 = div1 / 10) << 3) - (div2 << 1)) | '0';
        st[0] = (div2 - ((div1 = div2 / 10) << 3) - (div1 << 1)) | '0';
    }
    *st = '\0', st = buffer;
    while (*st == '0')
        st++;
    puts(st);
}

int main()
{
    int m;
    while ((readUInt(&n->Num[0]), readUInt(&m)) && n->Num[0] + m)
    {
        n->Last = 0;
        pow(ans, n, m);
        putUBigNum(output, ans);
    }
    return 0;
}