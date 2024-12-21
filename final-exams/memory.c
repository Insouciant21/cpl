#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int l, r;
    struct Node* prev, * next;
    int used;
} Node;

Node* alloc[5001];
Node* head;

Node* allocate(int size)
{
    Node* p = head;
    for (; p; p = p->next)
    {
        if (p->used) continue;
        if (p->r - p->l < size) continue;
        break;
    }
    if (p == NULL) return NULL;
    if (p->r - p->l == size)
    {
        p->used = 1;
        return p;
    }
    Node* new_node = calloc(1, sizeof(Node));
    new_node->l = p->l; new_node->r = p->l + size;
    new_node->prev = p->prev;
    if (p->prev != NULL)p->prev->next = new_node;
    p->prev = new_node;
    new_node->next = p;
    p->l = p->l + size;
    new_node->used = 1;
    if (p == head) head = new_node;
    return new_node;
}

void merge(Node* lhs, Node* rhs)
{
    if (rhs->next != NULL) rhs->next->prev = lhs;
    lhs->next = rhs->next;
    lhs->r = rhs->r;
    free(rhs);
}

int freeNode(int id)
{
    Node* toBeFreed = alloc[id];
    if (toBeFreed == NULL) return 1;
    toBeFreed->used = 0;
    if (toBeFreed->next && toBeFreed->next->used == 0) merge(toBeFreed, toBeFreed->next);
    if (toBeFreed->prev && toBeFreed->prev->used == 0) merge(toBeFreed->prev, toBeFreed);
    alloc[id] = NULL;
    return 0;
}

int main(void)
{
    int T, id = 0, n;
    scanf("%d%d", &T, &n);
    head = calloc(1, sizeof(Node));
    head->l = 0; head->r = n; head->next = NULL;
    head->used = 0;
    head->prev = NULL;
    while (T--)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int size;
            scanf("%d", &size);
            Node* allocated = allocate(size); id++;
            if (allocated == NULL) puts("malloc fail");
            else  printf("%d\n", allocated->l);
            alloc[id] = allocated;
        }
        if (op == 2)
        {
            int idx;
            scanf("%d", &idx);
            if (idx > id || freeNode(idx)) puts("free fail");
            else puts("free success");
        }
        if (op == 3)
        {
            Node* p = head;
            int flags = 0;
            for (; p; p = p->next)
            {
                if (p->used == 0)
                {
                    printf("[%d,%d) ", p->l, p->r);
                    flags = 1;
                }
            }
            if (!flags) printf("NULL");
            printf("\n");
        }
    }
}