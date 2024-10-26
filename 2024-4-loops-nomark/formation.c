#include <stdio.h>
#include <string.h>
int p[9], a[3000][3000];
int main() {
    char str[3000];
    int n, m;
    scanf("%d %d %s", &m, &n, str);
    p[0] = p[4] = p[7] = 0;
    p[1] = p[2] = p[3] = p[5] = p[6] = 1;
    for (int i = 0; i < strlen(str); i++) a[0][i] = str[i] - '0';
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0) a[i][j] = p[(a[i - 1][j] << 1) + a[i - 1][j + 1]];
            else if (j == n - 1) a[i][j] = p[(a[i - 1][j - 1] << 2) + (a[i - 1][j] << 1)];
            else a[i][j] = p[(a[i - 1][j - 1] << 2) + (a[i - 1][j] << 1) + a[i - 1][j + 1]];
        }
    }
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) printf("%d", a[i][j]);
        printf("\n");
    }
    return 0;
}