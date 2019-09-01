#include <stdio.h>
#include <string.h>
#define BUKCNT 3371
#define BUKSIZ 10010

typedef struct
{
    unsigned int Next;
    char Name[30], AC, FAC;
} Node;

unsigned int buckets[BUKCNT], lastNode;
Node dict[BUKSIZ];

unsigned int Hash(char src[])
{
    unsigned int hash = 0;
    while (*src++)
    {
        hash ^= (~((hash << 11) ^ *(src) ^ (hash >> 5)));
        if (*src++) break;
        hash ^= ((hash << 7) ^ *(src) ^ (hash >> 3));
    }
    return (hash & 0x7FFFFFFF);
}

void addNode(char name[], char status[])
{
    int Key = Hash(name);
    int targetBuk = Key % 3371, currNode = buckets[targetBuk];
    while (currNode)
    {
        if (!strcmp(dict[currNode].Name, name))
        {
            if (status[0] == 'A')
                dict[currNode].AC = 1;
            dict[currNode].FAC = (status[0] == 'A');
            return;
        }
        currNode = dict[currNode].Next;
    }
    currNode = ++lastNode;
    dict[currNode].Next = buckets[targetBuk];
    buckets[targetBuk] = currNode;
    strcpy(dict[currNode].Name, name);
    dict[currNode].AC = dict[currNode].FAC = (status[0] == 'A');
}

int main()
{
    int n, FAC = 0, AC = 0;
    char name[30], status[4];
    scanf(" %d", &n);
    for (int i = n; i; i--)
    {
        scanf(" %s %s", name, status);
        addNode(name, status);
    }
    for (int i = n; i; i--)
    {
        if (dict[i].FAC)
            FAC += 100, AC++;
        else if (dict[i].AC)
            AC++;
    }
    printf("%d%%", FAC / AC);
    return 0;
}