#include <stdio.h>
#define SWAP(x, y) (x)^=((y)^=((x)^=(y)))

typedef struct Node
{
    int score, dec;
} Node;

Node heap[1010];

int last, now, base, derived;

void swapNode(int lhs, int rhs)
{
    SWAP(heap[lhs].score, heap[rhs].score), SWAP(heap[lhs].dec, heap[rhs].dec);
}

void insNode()
{
    last++;
    scanf(" %d %d", &heap[last].score, &heap[last].dec);
    now = last, base = now >> 1;
    while (base && heap[now].score > heap[base].score)
        swapNode(now, base), now >>= 1, base >>= 1;
}

void heapify()
{
    now = 1, derived = 2;
    while (derived <= last)
    {
        if (heap[derived].score < heap[derived + 1].score && derived < last)
            derived++;
        if (heap[derived].score < heap[now].score)
            break;
        swapNode(now, derived), now = derived, derived <<= 1;
    }
}

int main()
{
    int n, t, ans;
    while (scanf(" %d %d", &n, &t) == 2)
    {
        ans = last = 0;
        while (n--)
            insNode();
        while (t--)
        {
            ans += heap[1].score;
            heap[1].score -= heap[1].dec;
            heapify();
            if (last && heap[last].score <= 0)
                last--;
        }
        printf("%d\n", ans);
    }
    return 0;
}