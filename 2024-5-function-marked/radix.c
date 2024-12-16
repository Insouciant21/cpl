#include <stdio.h>

int dest(int f, int base) {
    int ret = 0, t = 1;
    while (f) {
        if (f % 10 >= base) return -1;
        ret += f % 10 * t;
        t *= base;
        f /= 10;
    }
    return ret;
}
int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int ans = 0;
    for (int i = 2; i <= 40; i++) {
        int m = 0, n = 0, k = 0;
        m = dest(a, i), n = dest(b, i), k = dest(c, i);
        if (m == -1 || n == -1 || k == -1) continue;
        if (m * n == k) {
            ans = i;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}