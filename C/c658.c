#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Hash
{
    unsigned int Key, vLen;
    char Values[40][11];
    struct Hash* Next;
}Hash;

Hash* pList[32768];
Hash** now;
long long tmp;
unsigned int key, pLen;
char value[11];

inline unsigned int APHash(char src[])
{
    unsigned int hash = 0;
    char str[10] = { 0 };
    for (int i = 0; src[i]; i++)
        str[src[i] - '0']++;
    for (int i = 9; i; i--)
    {
        if (i & 1)
            hash ^= (~((hash << 11) ^ (str[i]) ^ (hash >> 5)));
        else
            hash ^= ((hash << 7) ^ (str[i]) ^ (hash >> 3));
    }
    return (hash & 0x7FFFFFFF);
}

inline void addHash(long long square)
{
    sprintf(value, "%lld", square);
    key = APHash(value);
    now = &pList[key & 32767];
    while (*now)
    {
        if ((*now)->Key == key)
        {
            strcpy((*now)->Values[(*now)->vLen++], value);
            return;
        }
        now = &(*now)->Next;
    }
    (*now) = malloc(sizeof(Hash));
    (*now)->Key = key;
    (*now)->vLen = 1;
    strcpy((*now)->Values[0], value);
    (*now)->Next = NULL;
}

inline void getAns(char src[])
{
    key = APHash(src);
    now = &pList[key & 32767];
    while (*now)
    {
        if ((*now)->Key == key)
        {
            for (int i = 0; i < (*now)->vLen; i++)
                printf("%s ", (*now)->Values[i]);
            putchar('\n');
            return;
        }
        now = &(*now)->Next;
    }
    puts("0");
}

int main()
{
    for (long long i = 34; i < 100000; i++)
    {
        tmp = i * i;
        while (tmp % 10)
            tmp /= 10;
        if (!tmp)
            addHash(i * i);
    }
    while (scanf(" %s", value) == 1)
    {
        getAns(value);
    }
    return 0;
}