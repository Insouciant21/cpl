#include <stdio.h>
#include <string.h>
int a[1001][1001];

int main() {
    int n;
    scanf("%d", &n);
    int x = 0, y = (n - 1) / 2;
    int pos = 1, remain = n * n;
    memset(a, 0x3f, sizeof a);
    while (remain--) {
        a[x][y] = pos++;
        int nx = x - 1, ny = y + 1;
        if (ny >= n) ny -= n;
        if (nx < 0) nx += n;
        if (a[nx][ny] != 0x3f3f3f3f) nx = x + 1, ny = y;
        x = nx, y = ny;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", a[i][j]);
        printf("\n");
    }
}
