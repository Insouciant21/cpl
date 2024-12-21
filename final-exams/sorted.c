#include <stdio.h>
#include <string.h>

int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m, a[1005];
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) scanf("%d", a + i);
        for (int i = 0, x; i < m; i++) {
            scanf("%d", &x);
            int tmp = a[x - 1];
            memmove(a + 1, a, (x - 1) * sizeof(int));
            a[0] = tmp;
        }
        int flags = 0;
        for (int i = 0; i < n - 1; i++)
            if (a[i] > a[i + 1]) flags = 1;
        if (flags)
            puts("mayi is a good teacher");
        else
            puts("I love C programming language");
    }
    return 0;
}
