#include <stdio.h>

int prime(int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return 0;
    return 1;
}

int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int t = 0, p = i;
        while (p) {
            t = t * 10 + p % 10;
            p /= 10;
        }
        if (prime(t) && prime(i)) cnt++;
    }
    printf("%d\n", cnt);
}