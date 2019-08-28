#include <stdio.h>
#define BUFSIZE 1048576

int stone[BUFSIZE], cont[BUFSIZE];

inline char readChar()
{
    static char buffer[BUFSIZE], * now = buffer + BUFSIZE, * end = buffer + BUFSIZE;
    if (now == end)
    {
        if (end < buffer + BUFSIZE)
            return EOF;
        end = (buffer + fread(buffer, 1, BUFSIZE, stdin));
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

int main()
{
    unsigned int tmp, len = 0;
    while (readUInt(&tmp))
    {
        for (int i = 0; i < len; i++)
        {
            if (stone[i] == tmp)
            {
                if (cont[i] == 2)
                    stone[i] = stone[--len], cont[i] = cont[len];
                else
                    cont[i]++;
                goto end;
            }
        }
        stone[len] = tmp, cont[len++] = 1;
    end:;
    }
    printf("%d", stone[0]);
    return 0;
}