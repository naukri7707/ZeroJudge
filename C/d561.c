#include <stdio.h>

char buffer[110], * num;

int main()
{
    while (scanf(" %s", buffer) == 1)
    {
        num = buffer[0] == '-' ? buffer + 1 : buffer;
        if (num[3] == '\0')
            num[3] = '0', num[4] = '\0';
        else if (num[4] >= '5')
            num[3]++;
        for (int i = 3; ~i; i--)
        {
            if (num[i] > '9')
            {
                if (num[i - 1] == '.') num[i - 2]++;
                else num[i - 1]++;
                num[i] = '0';
            }
            else break;
        }
        num[4] = '\0';
        puts((num[0] == '0' && num[2] == '0' && num[3] == '0') ? "0.00" : buffer);
    }
    return 0;
}