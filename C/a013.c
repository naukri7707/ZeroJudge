#include<stdio.h>

typedef struct node
{
    char Str[3];
    int Val;
}Node;

int n, m, gap;
Node table[13] = { {"M" , 1000} , {"CM" , 900} ,{"D" , 500} ,{"CD" , 400}
                  ,{"C" , 100} ,{"XC" , 90} ,{"L" , 50} ,{"XL" , 40}
                  ,{"X" , 10} ,{"IX" , 9} ,{"V" , 5} ,{"IV" , 4} ,{"I" , 1} };

char strN[10], strM[10], strGap[10], * ptGap;

int toNum(char* src)
{
    char* pt = src - 1;
    int res = 0, prev, curr = 0;
    while (*(++pt))
    {
        prev = curr;
        if (*pt == 'I') curr = 1;
        else if (*pt == 'V') curr = 5;
        else if (*pt == 'X') curr = 10;
        else if (*pt == 'L') curr = 50;
        else if (*pt == 'C') curr = 100;
        else if (*pt == 'D') curr = 500;
        else if (*pt == 'M') curr = 1000;
        //
        if (prev < curr)
            res += curr - (prev << 1);
        else
            res += curr;
    }
    return res;
}

int main()
{
    while (scanf(" %s %s", strN, strM) == 2 && strN[0] != '#')
    {
        n = toNum(strN), m = toNum(strM);
        gap = n > m ? n - m : m - n;
        if (gap)
        {
            ptGap = strGap;
            for (int i = 0; i < 13; i++)
            {
                while (gap >= table[i].Val)
                {
                    char* tmp = table[i].Str - 1;
                    while (*(++tmp))
                        * ptGap++ = *tmp;
                    gap -= table[i].Val;
                }
            }
            *ptGap = '\0';
            puts(strGap);
        }
        else
        {
            puts("ZERO");
        }
    }
    return 0;
}