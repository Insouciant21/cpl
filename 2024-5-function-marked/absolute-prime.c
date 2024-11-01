#include <stdio.h>

int prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int t = 0, c = 0, p = i;
        c = prime(p);
        while (p) {
            t += p % 10;
            t *= 10;
            p /= 10;
        }
        t /= 10;
        if (prime(t) && c) cnt++;
    }
    printf("%d\n", cnt);
}