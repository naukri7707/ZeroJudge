#include <stdio.h>
#include <string.h>
#define MAX 550

typedef struct node
{
    int Length, First;
    char String[MAX + 1];
}Node;

Node input1, input2;
char op, nag;

void toDigit(Node* src)
{
    src->Length = strlen(src->String);
    int i = 0;
    for (; i < src->Length; i++)
        src->String[MAX - i] = src->String[src->Length - i - 1] - '0';
    src->First = MAX - i + 1;
    for (; MAX - i >= 0; i++)
        src->String[MAX - i] = 0;
}

char cmp(Node* lhs, Node* rhs)
{
    if (lhs->Length > rhs->Length)
        return 1;
    else if (lhs->Length < rhs->Length)
        return -1;
    else
    {
        int i = 0;
        while (lhs->String[lhs->First] == rhs->String[rhs->First] && i < lhs->Length)
            i++;
        if (lhs->String[lhs->First] >= rhs->String[rhs->First])
            return 1;
        else
            return -1;
    }
}

void cale(Node* lhs, Node* rhs, Node* sum, char op)
{
    switch (op)
    {
    case '+':
        for (int i = MAX; i >= lhs->First; i--)
        {
            sum->String[i] += lhs->String[i] + rhs->String[i];
            if (sum->String[i] >= 10)
            {
                sum->String[i - 1]++;
                sum->String[i] -= 10;
            }
        }
        if (sum->String[sum->First - 1] > 0)
            sum->First--;
        break;
    case '-':
        for (int i = MAX; i >= lhs->First; i--)
        {
            sum->String[i] += lhs->String[i] - rhs->String[i];
            if (sum->String[i] < 0)
            {
                sum->String[i - 1]--;
                sum->String[i] += 10;
            }
        }
        break;
    case '*':
        for (int i = 0; i < lhs->Length; i++)
        {
            for (int j = 0; j < rhs->Length; j++)
            {
                sum->String[MAX - (i + j)] += lhs->String[MAX - i] * rhs->String[MAX - j];
                if (sum->String[MAX - (i + j)] >= 10)
                {
                    sum->String[MAX - (i + j) - 1] += sum->String[MAX - (i + j)] / 10;
                    sum->String[MAX - (i + j)] %= 10;
                }
            }
        }
        break;
    case '/':
        if (nag) return;
        sum->First = MAX;
        int i = 0, gap = lhs->Length - rhs->Length;
        if (lhs->Length > rhs->Length)
        {
            for (; i < rhs->Length; i++)
                rhs->String[lhs->First + i] = rhs->String[rhs->First + i];
            for (; lhs->First + i <= MAX; i++)
                rhs->String[lhs->First + i] = 0;
            rhs->Length = lhs->Length;
            rhs->First = MAX - rhs->Length + 1;
        }
        //
        for (int i = 0; i <= gap; i++)
        {
            for (int i = sum->First; i < MAX; i++)
                sum->String[i] = sum->String[i + 1];
            sum->String[MAX] = 0;
            while (cmp(lhs, rhs) == 1)
            {
                for (int i = MAX; i >= lhs->First; i--)
                {
                    lhs->String[i] -= rhs->String[i];
                    if (lhs->String[i] < 0)
                    {
                        lhs->String[i - 1]--;
                        lhs->String[i] += 10;
                    }
                }
                while (lhs->String[lhs->First] == 0 && lhs->Length > 1)
                    lhs->First++, lhs->Length--;
                sum->String[MAX]++;
            }
            for (int i = MAX; i > rhs->First; i--)
                rhs->String[i] = rhs->String[i - 1];
            sum->First--;
            rhs->String[rhs->First++] = 0;
            rhs->Length--;
        }
        break;
    default:
        break;
    }
}

int main()
{
    while (scanf(" %s %c %s", input1.String, &op, input2.String) == 3)
    {
        Node* lhs, * rhs, sum = { 0 };
        toDigit(&input1), toDigit(&input2);
        if (cmp(&input1, &input2) == 1)
            lhs = &input1, rhs = &input2, nag = 0;
        else
            lhs = &input2, rhs = &input1, nag = 1;
        //
        cale(lhs, rhs, &sum, op);
        //
        while (sum.String[sum.First] == 0)
            sum.First++;
        if (sum.First > MAX || (nag && op == '/'))
            puts("0");
        else
        {
            if (nag && op == '-')
                putchar('-');
            for (int i = sum.First; i <= MAX; i++)
                sum.String[i] += '0';
            puts(&sum.String[sum.First]);
        }
    }
}