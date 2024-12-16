#include <stdio.h>
const int maxN = (int)1e5 + 10;

int main() {
    int n, t, p = 0x3f3f3f3f, s = 0;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        scanf("%d", &t);
        if (i != 0) p = p < s - i ? p : s - i;
        s += t;
    }
    printf("%d\n", p < 0 ? -p : 0);
    return 0;
}
