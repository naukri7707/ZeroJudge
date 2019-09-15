#include <stdio.h>
#define MAX 255
#define MAX2 62500

typedef struct
{
    int val[4], * top;
}Stack;

typedef struct
{
    int val, next;
}Query;

Stack list[MAX2];
Query qList[50005];
int sum, len, qTop, depth[MAX2];
int map[MAX][MAX], parent[MAX2], query[MAX2];
char input[MAX][MAX];

void dfs(int i, int j, int dep)
{
    int idx = ++len;
    parent[idx] = map[i][j] = idx;
    depth[idx] = dep;
    list[idx].top = list[idx].val;
    if (input[i + 1][j] == '.' && !map[i + 1][j])
        dfs(i + 1, j, dep + 1), * list[idx].top++ = map[i + 1][j];
    if (input[i - 1][j] == '.' && !map[i - 1][j])
        dfs(i - 1, j, dep + 1), * list[idx].top++ = map[i - 1][j];
    if (input[i][j + 1] == '.' && !map[i][j + 1])
        dfs(i, j + 1, dep + 1), * list[idx].top++ = map[i][j + 1];
    if (input[i][j - 1] == '.' && !map[i][j - 1])
        dfs(i, j - 1, dep + 1), * list[idx].top++ = map[i][j - 1];
}

inline void setDepth(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (input[i][j] == '.')
            {
                dfs(i, j, 0);
                return;
            }
        }
    }
}

inline void addQuery(int from, int to)
{
    qTop++;
    qList[qTop].val = to;
    qList[qTop].next = query[from];
    query[from] = qTop;
}

int find(int i)
{
    return i == parent[i] ? i : (parent[i] = find(parent[i]));
}

void tarjan(int i)
{
    for (Query* j = &qList[query[i]]; j->val; j = &qList[j->next])
        sum += depth[i] + depth[j->val] - (depth[find(j->val)] << 1);
    for (int* j = list[i].val; j < list[i].top; j++)
    {
        tarjan(*j);
        parent[*j] = i;
    }
}

int main()
{
    int n, m, q, sX, sY, eX, eY, s, e;
    scanf(" %d %d %d", &n, &m, &q);
    getchar();
    for (int i = 0, idx = 0; i < n; i++)
        gets(input[i]);
    setDepth(n, m);
    for (int i = 0; i < q; i++)
    {
        scanf(" %d %d %d %d", &sX, &sY, &eX, &eY);
        s = map[sX][sY], e = map[eX][eY];
        if (s < e)
            addQuery(e, s);
        else
            addQuery(s, e);
    }
    tarjan(1);
    printf("%d\n", sum);
    return 0;
}
