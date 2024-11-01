#include <stdio.h>
#define maxn  1000005
int a[maxn], b[maxn];

int main(void) {
    int n, m, t, minB = 0x3f3f3f;
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < m; i++) scanf("%d", b + i), minB = minB > b[i] ? b[i] : minB;
    if (t < minB + a[0]) puts("-1");
    else {
        int ans = 2147483647;
        for (int i = 0; i < m; i++) {
            int l = 0, r = n, c = t - b[i];
            if (c - a[0] < 0) continue;
            while (l < r) {
                int mid = (l + r) / 2;
                if (a[mid] >= c) r = mid;
                else l = mid + 1;
            }
            if (a[l] == c) ans = 0;
            else if (l != 0) ans = ans > c - a[l - 1] ? c - a[l - 1] : ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}