#include <stdio.h>

int main() {
    int n, t;
    long long sum = 0;
    scanf("%d%d", &n, &t);
    for (int i = 0, p = t; i < n; i++) sum += p, p = p * 10 + t;
    printf("%lld\n", sum);
}