#include <stdio.h>
#include <string.h>

int main() {
    int a[101][101];
    int n, m;
    scanf("%d %d", &n, &m);
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
    int identical = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0, t; j < m; j++) {
            scanf("%d", &t);
            if (t == a[i][j]) identical++;
        }
    }
    printf("%.2f\n", identical / (n * m * 1.0) * 100);
    return 0;
}