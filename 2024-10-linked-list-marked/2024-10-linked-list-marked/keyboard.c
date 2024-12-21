#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char val;
    struct Node* l, * r;
    struct Node* lastSame;
} Node;

char str[2000005];

int main(void) {
    int Q;
    scanf("%d", &Q);
    Node* tail = NULL, * lU = NULL, * lL = NULL;
    while (Q--) {
        scanf("%s", str);
        if (str[0] == '?') {
            int K;
            scanf("%d", &K);
            Node* p = tail;
            for (int i = 1; i < K ; i++)  p = p->l;
            while (p != NULL) { putchar(p->val); if (p == tail) break; p = p->r; }
            putchar('\n');
        }
        else {
            size_t len = strlen(str);
            for (size_t i = 0; i < len; i++) {
                if (str[i] != 'm' && str[i] != 'M') {
                    Node* ftr = malloc(sizeof(Node));
                    ftr->val = str[i];
                    ftr->l = tail;
                    ftr->r = NULL;
                    if (islower(ftr->val)) {
                        ftr->lastSame = lL;
                        lL = ftr;
                    }
                    if (isupper(ftr->val)) {
                        ftr->lastSame = lU;
                        lU = ftr;
                    }
                    if (tail != NULL) tail->r = ftr;
                    tail = ftr;
                }
                if (str[i] == 'm') {
                    Node* p = lL;
                    if (p == NULL) continue;
                    if (p == tail) tail = tail->l;
                    if (p->l != NULL)p->l->r = p->r;
                    if (p->r != NULL) p->r->l = p->l;
                    lL = p->lastSame;
                    free(p);
                }
                if (str[i] == 'M') {
                    Node* p = lU;
                    if (p == NULL) continue;
                    if (p == tail)tail = tail->l;
                    if (p->l != NULL)p->l->r = p->r;
                    if (p->r != NULL) p->r->l = p->l;
                    lU = p->lastSame;
                    free(p);
                }
            }
        }
    }
    return 0;
}