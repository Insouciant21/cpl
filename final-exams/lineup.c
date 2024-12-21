#include <stdio.h>

typedef struct Node {
    int val;
    struct Node* r, * d;
} Node;

Node a[2517][2517];
Node* rows[2517];

Node* find(int x, int y) {
    Node* res = rows[x];
    for (int ny = 0; ny < y; ny++) res = res->r;
    return res;
}

int main() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            a[i][j].val = i * m + j;
            a[i][j].d = &a[i + 1][j];
            a[i][j].r = &a[i][j + 1];
        }
        rows[i] = &a[i][0];
    }
    while (q--) {
        int x1, y1, x2, y2;
        int x3, y3, x4, y4;
        int line;
        scanf("%d%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4, &line);
        Node* rec1 = find(x1 - 1, y1 - 1), * rec2 = find(x3 - 1, y3 - 1);
        Node* rec3 = find(x1, y2), * rec4 = find(x3, y4);
        Node* rec5 = find(x2, y1), * rec6 = find(x4, y3);
        Node* a = rec1->d, * b = rec2->d;
        for (int i = x1; i <= x2; i++)
        {
            Node* p = a->r;
            a->r = b->r; b->r = p;
            a = a->d; b = b->d;
        }
        a = rec1->r; b = rec2->r;
        for (int i = y1; i <= y2; i++)
        {
            Node* p = a->d;
            a->d = b->d; b->d = p;
            a = a->r; b = b->r;
        }
        a = rec3; b = rec4;
        for (int i = x1; i <= x2; i++)
        {
            Node* p = a->r;
            a->r = b->r; b->r = p;
            a = a->d; b = b->d;
        }
        a = rec5; b = rec6;
        for (int i = y1; i <= y2; i++)
        {
            Node* p = a->d;
            a->d = b->d; b->d = p;
            a = a->r; b = b->r;
        }
        Node* cur = rows[line]->r;
        long long sum = 0;
        for (int i = 0; i < m; i++) {
            sum += cur->val;
            cur = cur->r;
        }
        printf("%lld\n", sum);
    }
}