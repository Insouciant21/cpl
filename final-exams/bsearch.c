#include <stdio.h>
#include <stdlib.h>
int a[1000007];
int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    while (q--) {
        int x;
        scanf("%d", &x);
        int *target = bsearch(&x, a, n, sizeof(int), cmp);
        if (target != NULL)
            printf("%ld\n", target - a);
        else
            printf("-1\n");
    }
    return 0;
}