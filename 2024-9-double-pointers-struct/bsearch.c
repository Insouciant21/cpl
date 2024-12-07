#include <stdio.h>
#include <stdlib.h>
int a[1000007];

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main(void) {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    while (q--) {
        int t;
        scanf("%d",&t);
        int *p = (int *)bsearch(&t, a, n, sizeof(int), cmp);
        if (p) printf("%lld\n", p - a);
        else printf("-1\n");
    }
    return 0;
}
