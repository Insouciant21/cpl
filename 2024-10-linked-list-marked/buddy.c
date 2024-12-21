#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    struct Node *next;
    int space;
    int id;
} Node;

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    Node *h = malloc(sizeof(Node));
    h->next = NULL, h->space = n, h->id = 0;
    int cnt = 1;
    while (q--) {
        char op[2];
        scanf("%s", op);
        if (op[0] == 'A') {
            int id, space;
            scanf("%d%d", &id, &space);
            int m = 0;
            while (1 << m < space) m++;
            Node *p = h;
            while (p != NULL) {
                if (p->space == m && p->id == 0) {
                    p->id = id;
                    break;
                }
                p = p->next;
            }
            if (p != NULL) continue;
            p = h;
            while (1) {
                if (p->space > m && p->id == 0) {
                    while (p->space != m) {
                        Node *s = malloc(sizeof(Node));
                        s->next = p->next;
                        p->next = s;
                        s->space = --(p->space);
                        s->id = 0;
                        cnt++;
                    }
                    p->id = id;
                    break;
                }
                p = p->next;
            }
        } else {
            Node *p = h;
            printf("%d\n", cnt);
            p = h;
            while (p != NULL) {
                printf("%d ", p->id);
                p = p->next;
            }
            puts("");
        }
    }
}