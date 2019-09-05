#include <stdio.h>
#define BUFSIZ 1048576
#define BUFMAX 1048570
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

int main()
{
    unsigned int n;
    register char* oTop = output;
    char* end = output + BUFMAX;
    while (readUInt(&n))
    {
        if (n & (n - 1) | !n)
            * oTop++ = 'N', * oTop++ = 'o', * oTop++ = '\n';
        else
            *oTop++ = 'Y', * oTop++ = 'e', * oTop++ = 's', * oTop++ = '\n';
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