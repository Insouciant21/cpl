#include <stdio.h>

const int MAX = 10007;
int main() {
    long long p = 1, s = 0;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        p = p * i % MAX;
        s = (s + p) % MAX;
    }
    printf("%lld", s);
    return 0;
}
