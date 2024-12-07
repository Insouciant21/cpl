#include <stdio.h>
#include <stdlib.h>

typedef struct Team {
    char name[30];
    struct Player {
        char name[30];
        int atk, def, org;
    } player[21];
    int sumAtk, sumDef, sumOrg;
} Team;

Team p[1004];

void calculate(Team *t) {
    for (int i = 0; i < 11; i++) {
        t->sumAtk += t->player[i].atk;
        t->sumDef += t->player[i].def;
        t->sumOrg += t->player[i].org;
    }
}

int cmp1(const void *a, const void *b) { return ((Team *)b)->sumAtk - ((Team *)a)->sumAtk; }
int cmp2(const void *a, const void *b) { return ((Team *)b)->sumDef - ((Team *)a)->sumDef; }
int cmp3(const void *a, const void *b) { return ((Team *)b)->sumOrg - ((Team *)a)->sumOrg; }
int (*cmp[3])(const void *, const void *) = {cmp1, cmp2, cmp3};
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        Team *x = p + i;
        scanf("%s", x->name);
        for (int j = 0; j < 11; j++) {
            struct Player *y = x->player + j;
            scanf("%s %d %d %d", y->name, &y->atk, &y->def, &y->org);
        }
        calculate(x);
    }
    for (int i = 0; i < 3; i++) {
        qsort(p, n, sizeof(Team), cmp[i]);
        for (int j = 0; j < n; j++) printf("%s ", p[j].name);
        printf("\n");
    }
}