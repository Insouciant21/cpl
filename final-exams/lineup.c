#pragma GCC optimize("O3")
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int val;
    struct Node *r, *d, *u, *l;
} Node;
Node *head;

Node *find(int x, int y) {
    Node *res = head;
    for (int nx = 1; nx < x; nx++) res = res->d;
    for (int ny = 1; ny < y; ny++) res = res->r;
    return res;
}

void buildList(int n, int m) {
    head = (Node *)malloc(sizeof(Node));
    head->val = m + 1;
    Node *cur = head, *lastLine = NULL;
    for (int i = 0; i < n; i++) {
        Node *up = lastLine;
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) continue;
            Node *newNode = malloc(sizeof(Node));
            newNode->val = (i + 1) * m + j + 1;
            cur->r = newNode, newNode->l = cur;
            if (up != NULL) {
                up->d = newNode;
                newNode->u = up;
                up = up->r;
            } else
                newNode->u = NULL;
            cur = newNode;
            if (j == m - 1) cur->r = NULL;
        }
        if (lastLine == NULL)
            lastLine = head;
        else
            lastLine = lastLine->d;
        cur = lastLine->d = malloc(sizeof(Node));
        cur->val = (i + 1) * m + 1;
        cur->u = lastLine;
    }
}

int main() {
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    double p = clock();
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    buildList(n, m);
    while (q--) {
        int x1, y1, x2, y2;
        int x3, y3, x4, y4;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        scanf("%d%d%d%d", &x3, &y3, &x4, &y4);
        Node *rec1 = find(x1, y1), *rec2 = find(x3, y3);
        Node *rx1 = rec1, *rx2 = rec2;
        for (int i = 0; i < x2 - x1; i++) rx1 = rx1->d, rx2 = rx2->d;
        for (int i = 0; i < y2 - y1; i++) rx1 = rx1->r, rx2 = rx2->r;
        Node *a = rec1, *b = rec2, *c = rx1, *d = rx2;
        for (int i = y1; i <= y2; i++) {
            if (a->u != NULL) a->u->d = b;
            if (b->u != NULL) b->u->d = a;
            Node *tmp = a->u;
            a->u = b->u, b->u = tmp;
            a = a->r, b = b->r;
            if (c->d != NULL) c->d->u = d;
            if (d->d != NULL) d->d->u = c;
            tmp = c->d;
            c->d = d->d, d->d = tmp;
            c = c->l, d = d->l;
        }
        a = rec1, b = rec2, c = rx1, d = rx2;
        for (int i = x1; i <= x2; i++) {
            if (a->l != NULL) a->l->r = b;
            if (b->l != NULL) b->l->r = a;
            Node *tmp = a->l;
            a->l = b->l, b->l = tmp;
            a = a->d, b = b->d;
            if (c->r != NULL) c->r->l = d;
            if (d->r != NULL) d->r->l = c;
            tmp = c->r;
            c->r = d->r, d->r = tmp;
            c = c->u, d = d->u;
        }
        if (x1 == 1 && y1 == 1) head = rec2;
        if (x3 == 1 && y3 == 1) head = rec1;
        int line;
        scanf("%d", &line);
        Node *cur = find(line, 1);
        long long sum = 0;
        for (int i = 0; i < m; i++) {
            sum += cur->val;
            cur = cur->r;
        }
        printf("%lld\n", sum);
    }
    printf("%f", (clock() - p) / 1000);
    return 0;
}