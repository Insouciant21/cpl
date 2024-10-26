#include <stdio.h>

int main(void) {
    long long a, b;
    scanf("%lld%lld", &a, &b);
    long long cnt = 0, p = a;
    while (p) {
        if (p & 1) cnt++;
        p >>= 1;
    }
    printf(
        "%lld\n%lld\n%lld\n%lld\n%lld\n%lld\n%lld\n%lld\n", a & b, a | b, a ^ b, ~a, a << b, a >> b, a >> b & 1, cnt);
}
