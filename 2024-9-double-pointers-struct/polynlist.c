#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Poly {
    int exp[25000];
} Poly;

char *convert(int s, int isTop, int isZero) {
    if (s == 1) return isTop ? "" : "+";
    if (s == -1) return isZero ? "-1" : "-";
    char *c = calloc(15, sizeof(char));
    c[0] = s > 0 ? '+' : '-';
    sprintf(isTop && s > 0 ? c : c + 1, "%d", s > 0 ? s : -s);
    return c;
}
char *con2(char *name, int i) {
    char *c = calloc(15, sizeof(char));
    if (i == 0)
        sprintf(c, "");
    else if (i == 1)
        sprintf(c, "%s", name);
    else
        sprintf(c, "%s^%d", name, i);
    return c;
}

void output(const Poly a, char *name) {
    int high = 25000, low = 0;
    for (int i = 24999; i >= 0; i--) {
        if (a.exp[i]) {
            high = i;
            break;
        }
    }
    for (int i = 0; i < 25000; i++) {
        if (a.exp[i]) {
            low = i;
            break;
        }
    }
    for (int i = high; i >= low; i--) {
        if (a.exp[i] == 0) continue;
        char *c = convert(a.exp[i], i == high, i == 0);
        char *p = con2(name, i);
        printf("%s%s", c, p);
        free(c), free(p);
    }
    puts("");
}

Poly poly1, poly2, ans;
int main() {
    int p1, p2;
    scanf("%d%d", &p1, &p2);
    char var[14];
    scanf("%s", var);
    for (int i = p1; i >= 0; i--) scanf("%d", &poly1.exp[i]);
    for (int i = p2; i >= 0; i--) scanf("%d", &poly2.exp[i]);
    memset(ans.exp, 0, sizeof(ans.exp));
    for (int i = 0; i <= (p1 < p2 ? p2 : p1); i++) ans.exp[i] = poly1.exp[i] + poly2.exp[i];
    output(ans, var);
    memset(ans.exp, 0, sizeof(ans.exp));
    for (int i = 0; i <= (p1 < p2 ? p2 : p1); i++) ans.exp[i] = poly1.exp[i] - poly2.exp[i];
    output(ans, var);
    memset(ans.exp, 0, sizeof(ans.exp));
    for (int i = 0; i <= (p1 < p2 ? p2 : p1); i++) {
        for (int j = 0; j <= (p1 < p2 ? p2 : p1); j++) {
            ans.exp[i + j] += poly1.exp[i] * poly2.exp[j];
        }
    }
    output(ans, var);
    return 0;
}