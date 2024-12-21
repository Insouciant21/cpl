#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char val;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    Node* tail;
} List;

char s[10005];
int n, m;
typedef struct Rule
{
    char s[105];
    char t[105];
    size_t len;
} Rule;

Rule rules[105];

void build(List* list, const char* str)
{
    list->head = calloc(1, sizeof(Node));
    list->tail = calloc(1, sizeof(Node));
    list->head->next = list->tail;
    list->tail->next = NULL;
    Node* cur = list->head;
    size_t len = strlen(str);
    for (size_t i = 0; i < len; i++)
    {
        Node* ftr = calloc(1, sizeof(Node));
        ftr->val = str[i];
        ftr->next = cur->next;
        cur->next = ftr;
        cur = ftr;
    }
}
List str;
Node* match(Node* start, const char* s)
{
    const char* p = s;
    while (*p && start != str.tail && start->val == *p)
    {
        start = start->next; p++;
    }
    if (*p) return NULL;
    return start;
}

void freeNode(Node* l, Node* r)
{
    Node* cur = l->next;
    l->next = r;
    while (cur != r)
    {
        Node* tmp = cur;
        cur = cur->next;
        free(tmp);
    }
}

int main(void)
{

    scanf("%s", s);
    build(&str, s);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s", rules[i].s, rules[i].t);
        rules[i].len = strlen(rules[i].t);
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Node* cur = str.head;
            while (cur != str.tail)
            {
                Node* find = match(cur->next, rules[j].s);
                if (find == NULL) { cur = cur->next; continue; }
                Node* replace = cur;
                for (size_t k = 0; k < rules[j].len; k++)
                {
                    Node* ftr = calloc(1, sizeof(Node));
                    ftr->val = rules[j].t[k];
                    ftr->next = replace->next;
                    replace->next = ftr;
                    replace = ftr;
                }
                freeNode(replace, find);
                cur = cur->next;
            }
        }
    }
    Node* cur = str.head->next;
    while (cur != str.tail)
    {
        putchar(cur->val);
        cur = cur->next;
    }
    putchar('\n');
}