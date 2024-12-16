#include <stdio.h>

int main() {
    int n, k, result = 0;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) result = (result + k) % i;
    printf("%d\n", result + 1);
}
