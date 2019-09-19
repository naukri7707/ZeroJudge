#include <stdio.h>
#define MAX 1010
#define SWAP(x, y) (x)^=((y)^=((x)^=(y)))

typedef struct
{
    int x, y;
}Point;

Point quene1[MAX * 4], quene2[MAX * 4];
int map[MAX][MAX];
char input[100];

inline char* getUInt(register char buffer[], register unsigned int* dst)
{
    while (*buffer < '0')
        if (!*buffer++) return NULL;
    *dst = *buffer ^ '0';
    while (*++buffer >= '0')
        * dst = (*dst << 3) + (*dst << 1) + (*buffer ^ '0');
    return buffer;
}

inline void setMap(int map[][MAX], Point s, Point e, int val)
{
    if (e.x < s.x) SWAP(e.x, s.x);
    if (e.y < s.y) SWAP(e.y, s.y);
    for (int i = s.x; i <= e.x; i++)
    {
        for (int j = s.y; j <= e.y; j++)
            map[i][j] = val;
    }
}

int getAns(int row, int col, register Point* nowTop)
{
    Point* now = quene1, * next = quene2, * nextTop, * tmp;
    for (int step = 1;; step++)
    {
        if (nowTop == now)
            return -1;
        nextTop = next;
        while (now <= --nowTop)
        {
            if (map[nowTop->x][nowTop->y]) continue;
            map[nowTop->x][nowTop->y] = step;
            if (nowTop->x > 0)
            {
                if (map[nowTop->x - 1][nowTop->y])
                {
                    if (map[nowTop->x - 1][nowTop->y] == -2)
                        return step;
                }
                else nextTop->x = nowTop->x - 1, nextTop++->y = nowTop->y;
            }
            if (nowTop->x < row)
            {
                if (map[nowTop->x + 1][nowTop->y])
                {
                    if (map[nowTop->x + 1][nowTop->y] == -2)
                        return step;
                }
                else nextTop->x = nowTop->x + 1, nextTop++->y = nowTop->y;
            }
            if (nowTop->y > 0)
            {
                if (map[nowTop->x][nowTop->y - 1])
                {
                    if (map[nowTop->x][nowTop->y - 1] == -2)
                        return step;
                }
                else nextTop->x = nowTop->x, nextTop++->y = nowTop->y - 1;
            }
            if (nowTop->y < col)
            {
                if (map[nowTop->x][nowTop->y + 1])
                {
                    if (map[nowTop->x][nowTop->y + 1] == -2)
                        return step;
                }
                else nextTop->x = nowTop->x, nextTop++->y = nowTop->y + 1;
            }
        }
        tmp = now, now = next, next = tmp;
        nowTop = nextTop;
    }
}

int main()
{
    char* st;
    int n, m, ans;
    Point s, e, * nowTop = quene1;
    scanf("%d %d", &n, &m);
    scanf("%*s %d %d %d %d", &s.x, &s.y, &e.x, &e.y);
    if (e.x < s.x) SWAP(e.x, s.x);
    if (e.y < s.y) SWAP(e.y, s.y);
    int idx = 0;
    for (int i = s.x; i <= e.x; i++)
    {
        for (int j = s.y; j <= e.y; j++)
            nowTop->x = i, nowTop++->y = j;
    }
    scanf("%*s %d %d %d %d %*s", &s.x, &s.y, &e.x, &e.y);
    setMap(map, s, e, -2);
    getchar();
    while (gets(input) && input[1] != 'b')
    {
        st = getUInt(input, &s.x), st = getUInt(st, &s.y);
        st = getUInt(st, &e.x), st = getUInt(st, &e.y);
        setMap(map, s, e, -3);
    }
    ans = getAns(n - 1, m - 1, nowTop);
    if (ans == -1)
        puts("no path");
    else
        printf("%d", ans);
    return 0;
}