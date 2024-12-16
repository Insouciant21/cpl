#include <stdio.h>
int n, m, t, ans = 2147483647, a[1000005];

int main(void) {
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0, tmp, l = 0, r = n; i < m; i++, l = 0, r = n) {
        scanf("%d", &tmp);
        if (t - tmp - a[0] < 0) continue;
        while (l < r) {
            if (a[(l + r) / 2] <= t - tmp) l = (l + r) / 2 + 1;
            else r = (l + r) / 2 ;
        }
        ans = ans > t - tmp - a[l - 1] ? t - tmp - a[l - 1] : ans;
    }
    printf("%d\n", ans == 2147483647 ? -1 : ans);
    return 0;
}