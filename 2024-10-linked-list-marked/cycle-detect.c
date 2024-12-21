#include <stdio.h>

typedef struct Node {
    char str[30];
    struct Node *dest;
} Node;

Node p[100005];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1, x; i <= n; i++) {
        scanf("%s %d", p[i].str, &x);
        if (1 <= x && x <= n)
            p[i].dest = &p[x];
        else
            p[i].dest = NULL;
    }
    Node *header = &p[1];
    Node *t = header, *h = header;
    do {
        t = t->dest;
        h = h->dest;
        if (h != NULL) h = h->dest;
    } while (t != h &&h != NULL);
    if (h != NULL) {
        int length = 0;
        for (; t != h; t = t->dest) length++;
        t = header;
        while (t != h) {
            t = t->dest;
            h = h->dest;
        }
        puts(t->str);
    } else
        puts("-1");
    return 0;
}
