#include <stdio.h>
#define BUFSIZ 1048576

unsigned int mTable[55][1010];
char output[50000];

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

inline char readUInt(unsigned register int* dst)
{
    register char ch;
    while ((ch = readChar()) < '0')
        if (ch == EOF) return 0;
    *dst = ch ^ '0';
    while ((ch = readChar()) >= '0')
        * dst = (*dst << 3) + (*dst << 1) + (ch ^ '0');
    return 1;
}

inline char* setUInt(char buffer[], register unsigned int src, const char suffix)
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
    unsigned int n, tmp;
    char* oTop;
    for (int i = 1; i < 50; ++i)
    {
        for (int j = 1; j < 1000; ++j)
            mTable[i][j] = mTable[i][j - 1] + i;
    }
    while (readUInt(&n))
    {
        if (n <= 1)
        {
            puts("0");
            if (!n) continue;
        }
        else
        {
            oTop = output;
            while (--n)
            {
                readUInt(&tmp);
                oTop = setUInt(oTop, mTable[tmp][n], ' ');
            }
            *(oTop - 1) = '\0';
            puts(output);
        }
        readUInt(&tmp);
    }
    return 0;
}