#include <stdio.h>

long long exgcd(long long a, long long b, long long *x, long long *y) {
    if (b == 0) {
        *x = 1, *y = 0;
        return a;
    }
    long long d = exgcd(b, a % b, y, x);
    *y -= a / b * *x;
    return d;
}

int main() {
    int w, n, d;
    int a[1005];
    scanf("%d %d %d", &w, &n, &d);
    for (int i = 0; i < w; i++) {
        scanf("%lld", a + i);
        a[i]--;
    }
    int l = 0, r = w - 1;
    long long ans = 0;
    while (l < r) {
        long long b = (a[l] - a[r] + n) % n;
        long long x = 0, y = 0;
        long long D = exgcd(d, n, &x, &y);
        if (b % D) {
            puts("Impossible");
            return 0;
        }
        long long m = n / D;
        long long ret = (x * (b / D) % m + m) % m;
        if (m - ret <= ret) ret = m - ret;
        ans += ret;
        l++, r--;
    }
    printf("%lld\n", ans);
}