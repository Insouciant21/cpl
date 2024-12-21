#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
    B = 500
};

typedef struct Node
{
    char val[B];
    size_t size;
    struct Node* next;
} Node;

void split(Node* node, int x)
{
    Node* newNode = (Node*)calloc(1, sizeof(Node));
    newNode->size = node->size - x;
    for (size_t i = x; i < node->size; i++)
        newNode->val[i - x] = node->val[i];
    newNode->next = node->next;
    node->size = x;
    node->next = newNode;
}

void merge(Node* lhs, Node* rhs)
{
    if (lhs->next != rhs) return;
    if (lhs->size + rhs->size > B) return;
    for (size_t i = 0; i < rhs->size; i++)
        lhs->val[lhs->size + i] = rhs->val[i];
    lhs->size += rhs->size;
    lhs->next = rhs->next;
    free(rhs);
}

typedef struct pair
{
    Node* node;
    size_t pos;
}pair;

Node* head = NULL;

pair query(size_t index)
{
    Node* node = head;
    while (index >= node->size)
    {
        index -= node->size;
        node = node->next;
    }
    return (pair) { node, index };
}

void init(const char* str)
{
    head = calloc(1, sizeof(Node));
    Node* cur = head;
    size_t len = strlen(str);
    for (size_t i = 0, j; i < len; i += B)
    {
        const char* p = str + i;
        for (j = 0; j < B && *p; j++)
            cur->val[j] = *p++;
        cur->size = j;
    }
}

void insert(Node* node, const char* str)
{
    size_t buf = node->size;
    const char* pos = str;
    Node* cur = node;
    while (*pos)
    {
        if (buf == B)
        {
            Node* newNode = (Node*)calloc(1, sizeof(Node));
            newNode->size = 0;
            newNode->next = cur->next;
            buf = 0;
            cur->next = newNode;
            cur = newNode;
        }
        cur->val[buf++] = *pos++;
        cur->size++;
    }
    while (cur->next != NULL && cur->size + cur->next->size <= B) merge(cur, cur->next);
}

int main(void)
{
    int n, q;
    scanf("%d%d", &n, &q);
    char str[114514];
    scanf("%s", str);
    head = calloc(1, sizeof(Node));
    head->size = 0; head->next = NULL;
    insert(head, str);
    while (q--)
    {
        char op[2];
        scanf("%s", op);
        if (op[0] == 'Q')
        {
            int x;
            scanf("%d", &x);
            pair p = query(x - 1);
            printf("%c\n", p.node->val[p.pos]);
        }
        else
        {
            int pos;
            scanf("%d%s", &pos, str);
            pair p = query(pos);
            split(p.node, p.pos);
            insert(p.node, str);
        }
    }
    return 0;
}