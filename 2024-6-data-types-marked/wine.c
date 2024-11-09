#include <stdio.h>
#include <stdlib.h>

typedef struct Wine {
    int v, w;
} Wine;

int cmp(const void *p, const void *arg) {
    return -((Wine *)p)->v + ((Wine *)arg)->v;
}

int main(void) {
    int n, L;
    scanf("%d%d", &n, &L);
    Wine wine[10001];
    for (int i = 0; i < n; i++)
        scanf("%d", &wine[i].v);
    for (int i = 0; i < n; i++)
        scanf("%d", &wine[i].w);
    qsort(wine, n, (sizeof( Wine)), cmp);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (L >= wine[i].w) {
            ans += wine[i].v * wine[i].w;
            L -= wine[i].w;
        }
        else {
            ans += wine[i].v * L;
            break;
        }
    }
    printf("%lld\n", ans);
    return 0;
}