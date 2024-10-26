#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &m, &n);
    if (n == 1) n = 6;
    else n -= 2;
    for (int i = 1; i <= n; i++) printf("    ");
    for (int i = 1; i <= m; i++) {
        if ((i + n) % 7 == 0) printf("%2d\n", i);
        else printf("%2d  ", i);
    }
    return 0;
}
