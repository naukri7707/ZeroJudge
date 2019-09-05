#include <stdio.h>
#define BUFSIZ 1048576
#define BUFMAX 1048560
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

inline char readUInt(register unsigned int* dst)
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
        *(--st) = (src - ((div = src / 10) << 3) - (div << 1)) | '0';
    } while (src = div);
    while (*++res = *st++)
        ;
    if (suffix)* res++ = suffix;
    return res;
}

int main()
{
    unsigned int n, m;
    register char* oTop = output;
    char* end = output + BUFMAX;
    while (readUInt(&n), readUInt(&m))
    {
        oTop = setUInt(oTop, n + m, '\n');
        if (oTop > end)
        {
            *oTop = '\0';
            puts(output);
            oTop = output;
        }
    }
    *oTop = '\0';
    puts(output);
    return 0;
}