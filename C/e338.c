#pragma GCC optimize(3)
#include <stdio.h>
#define MAX 65535
#define BUFSIZ 1048576
#define BUFMAX 1048560
#define  BIT2(n)       n,         n+1,       n+1,        n+2
#define  BIT4(n)  BIT2(n),  BIT2(n+1),  BIT2(n+1),  BIT2(n+2)
#define  BIT6(n)  BIT4(n),  BIT4(n+1),  BIT4(n+1),  BIT4(n+2)
#define  BIT8(n)  BIT6(n),  BIT6(n+1),  BIT6(n+1),  BIT6(n+2)
#define BIT10(n)  BIT8(n),  BIT8(n+1),  BIT8(n+1),  BIT8(n+2)
#define BIT12(n) BIT10(n), BIT10(n+1), BIT10(n+1), BIT10(n+2)
#define BIT14(n) BIT12(n), BIT12(n+1), BIT12(n+1), BIT12(n+2)
#define BIT16(n) BIT14(n), BIT14(n+1), BIT14(n+1), BIT14(n+2)

const unsigned char TABLE[MAX + 1] = { BIT16(0) };
char output[BUFSIZ];

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

char* setUInt(char buffer[], register unsigned int src, const char suffix)
{
    register unsigned int div;
    char tmp[11], * st = tmp + 10, *res = buffer - 1;
    *st = 0;
    do
    {
        *(--st) = src - ((div = src / 10) << 3) - (div << 1) + '0';
    } while (src = div);
    while (*++res = *st++)
        ;
    if (suffix)* res++ = suffix;
    return res;
}

int main()
{
    int n;
    char *end = output + BUFMAX;
    register char* oTop = output;
    while (readUInt(&n))
    {
        oTop = setUInt(oTop, TABLE[n & MAX] + TABLE[(n >> 16) & MAX], '\n');
        if (oTop > end)
        {
            *oTop = 0;
            fputs(output, stdout);
            oTop = output;
        }
    }
    *oTop = 0;
    fputs(output, stdout);
    return 0;
}