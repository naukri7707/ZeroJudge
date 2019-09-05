#include <stdio.h>
#define BUFSIZ 1048576
#define BUFMAX 1048000

char output[BUFSIZ];

inline char readChar()
{
    static char buffer[BUFSIZ], * now = buffer + BUFSIZ, * end = buffer + BUFSIZ;
    if (now == end)
    {
        if (end < buffer + BUFSIZ)
            return 0;
        end = (buffer + fread(buffer, 1, BUFSIZ, stdin));
        now = buffer;
    }
    return *now++;
}

int main()
{
    register char tmp, * oTop = output, isOdd = 0, *max = output + BUFMAX;
    while (tmp = readChar())
    {
        if (tmp == ' ')
            isOdd = ~isOdd;
        else
        {
            if (isOdd)
                * oTop++ = ' ', isOdd = 0;
            *oTop++ = tmp;
            if (oTop > max)
            {
                *oTop = '\0';
                fputs(output, stdout);
                oTop = output;
            }
        }
    }
    *oTop = '\0';
    fputs(output, stdout);
    return 0;
}