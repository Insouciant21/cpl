#include <stdio.h>

int main(void) {
    int n;
    int and = -1, xor = 0, or = 0;
    scanf("%d", &n);
    for (int i = 0, t; i < n; i++) {
        scanf("%d", &t);
        if (t == 3 || (14 <= t && t <= 16) || t == 18) and &= t, xor ^= t, or |= t;
        else and &= 0, xor ^= 0, or ^= 0;
    }
    printf("%d %d %d\n", and, or, xor);
}
