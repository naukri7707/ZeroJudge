#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* lhs, * rhs;
}Node;

inline Node* newNode(int value)
{
    Node* res = malloc(sizeof(Node));
    res->value = value;
    res->lhs = res->rhs = NULL;
    return res;
}

inline void setNode(Node* now, int value)
{
    for (;;)
    {
        if (value < now->value)
        {
            if (now->lhs)
                now = now->lhs;
            else
            {
                now->lhs = newNode(value);
                break;
            }
        }
        else
        {
            if (now->rhs)
                now = now->rhs;
            else
            {
                now->rhs = newNode(value);
                break;
            }
        }
    }
}

void serchNode(Node* now)
{
    if (now)
    {
        printf("%d ", now->value);
        serchNode(now->lhs);
        serchNode(now->rhs);
        free(now);
    }
}

int main()
{
    int n, tmp;
    while (scanf(" %d", &n) == 1)
    {
        Node root = { 0 };
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            setNode(&root, tmp);
        }
        serchNode(root.rhs);
        putchar('\n');
    }
    return 0;
}