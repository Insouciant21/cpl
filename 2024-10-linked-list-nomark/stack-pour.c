#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct List {
    Node* head, * tail;
} List;

List p[1000005];

int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        p[i].head = (Node*)malloc(sizeof(Node));
        p[i].tail = (Node*)malloc(sizeof(Node));
        Node* ftr = malloc(sizeof(Node));
        p[i].head->next = p[i].tail->prev = ftr;
        p[i].head->prev = NULL; p[i].tail->next = NULL;
        ftr->prev = p[i].head; ftr->next = p[i].tail;
        ftr->val = i; p[i].head->val = -1; p[i].tail->val = -2;

    }
    while (m--) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (p[x].head->next == p[x].tail)continue;
        if (p[y].tail->val == -2) p[y].tail->next = p[x].tail;
        else p[y].tail->prev = p[x].tail;
        if (p[x].tail->val == -2) p[x].tail->next = p[y].tail;
        else p[x].tail->prev = p[y].tail;
        p[y].tail = p[x].head;
        p[x].head = malloc(sizeof(Node)); p[x].tail = malloc(sizeof(Node));
        p[x].head->next = p[x].tail; p[x].tail->prev = p[x].head;
        p[x].head->prev = NULL, p[x].tail->next = NULL;
        p[x].head->val = -1, p[x].tail->val = -2;
    }
    for (int i = 1; i <= n; i++) {
        if (p[i].head->next != p[i].tail) {
            Node* c = p[i].head->next;
            int d = 0, sec = 1;
            while (c != p[i].tail)
            {
                if (c->val == -2 || c->val == -1)
                {
                    if (!sec)
                    {
                        if (c->val == -1) d = 0;
                        else d = 1;
                        sec = 1;
                    }
                    else sec = 0;
                }
                else printf("%d ", c->val);
                if (d == 0) c = c->next;
                if (d == 1) c = c->prev;
            }
        }
        else {
            printf("0");
        }
        printf("\n");
    }
    return 0;
}
