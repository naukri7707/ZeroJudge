#include <stdio.h>
#include <stdlib.h>

typedef struct Hash
{
    unsigned int Key;
    int Value;
    struct Hash* Next;
}Hash;

Hash HashTable[1024];

inline void AddHash(int key, int value)
{
    Hash* now = &HashTable[key & 1023];
    while (now->Key != key)
    {
        if (now->Next == NULL)
        {
            now = now->Next = malloc(sizeof(Hash));
            now->Key = key;
            now->Next = NULL;
            now->Value = -value;
            return;
        }
        now = now->Next;
    }
    now->Value *= -value;
}

int getInner()
{
    int res = 0;
    Hash* now, * tmp;
    for (int i = 0; i < 1024; i++)
    {
        if (HashTable[i].Next != NULL)
        {
            now = HashTable[i].Next;
            do
            {
                if (now->Value > 0)
                    res += now->Value;
                tmp = now;
                now = now->Next;
                free(tmp);
            } while (now != NULL);
            HashTable[i].Next = NULL;
        }
    }
    return res;
}

int main()
{
    int n, m, v = 1;
    while (scanf(" %d:%d", &n, &m) == 2)
    {
        if (n + m)
            AddHash(n, m);
        else if (v)
            v = 0;
        else
            printf("%d\n", getInner()), v = 1;
    }
    return 0;
}