#include <stdio.h>
#include <stdlib.h>

typedef struct Hash
{
    unsigned int Key;
    int Count;
    struct Hash* Next;
}Hash;

Hash HashTable[1024];
unsigned int list[5];
int n;

int cmp(const unsigned int* lhs, const unsigned int* rhs)
{
    return *lhs - *rhs;
}

inline unsigned int toHash(unsigned int src[])
{
    return (src[0] << 28) + (src[1] << 21) + (src[2] << 14) + (src[3] << 7) + src[4];
}

inline void AddHash(unsigned int hash)
{
    Hash* now = &HashTable[hash & 1023];
    while (now->Key != hash)
    {
        if (now->Next == NULL)
        {
            now = now->Next = malloc(sizeof(Hash));
            now->Key = hash;
            now->Next = NULL;
            now->Count = 1;
            return;
        }
        now = now->Next;
    }
    now->Count++;
}

int PopularityCount()
{
    int max = 0, count = 0;
    Hash* now, * tmp;
    for (int i = 0; i < 1024; i++)
    {
        if (HashTable[i].Next != NULL)
        {
            now = HashTable[i].Next;
            do
            {
                if (max <= now->Count)
                {
                    if (max == now->Count)
                        count += max;
                    else
                        count = max = now->Count;
                }
                tmp = now;
                now = now->Next;
                free(tmp);
            } while (now != NULL);
            HashTable[i].Next = NULL;
        }
    }
    return count;
}

int main()
{
    while (scanf(" %d", &n) == 1 && n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf(" %u %u %u %u %u", &list[0], &list[1], &list[2], &list[3], &list[4]);
            qsort(list, 5, sizeof(unsigned int), cmp);
            AddHash(toHash(list));
        }
        printf("%d\n", PopularityCount());
    }
    return 0;
}