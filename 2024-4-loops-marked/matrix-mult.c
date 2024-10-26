#include <stdio.h>
#include <string.h>

int main(void) {
    int m, n, p;
    scanf("%d %d %d", &m, &n, &p);
    int a[200][200], b[200][200];
    memset(a, 0, sizeof a), memset(b, 0, sizeof b);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++) scanf("%d", &b[i][j]);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) sum += a[i][k] * b[k][j];
            printf("%d ", sum);
        }
        printf("\n");
    }
}
