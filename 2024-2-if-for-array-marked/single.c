#include <stdio.h>

int main() {
    int n, g = 0;
    scanf("%d", &n);
    for (int i = 0, t; i < 2 * n - 1; i++) {
        scanf("%d", &t);
        g = g ^ t;
    }
    printf("%d\n", g);
    return 0;
}
