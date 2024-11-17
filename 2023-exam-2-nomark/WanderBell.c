#include <stdio.h>
char a[3400][3400];

int d(char s) {
    switch (s) {
        case 'U': return 0;
        case 'D': return 1;
        case 'L': return 2;
        case 'R': return 3;
        default: return -1;
    }
}

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int r, c;

int search(int x, int y, int dir) {
    while (1) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c) return 1;
        if (d(a[nx][ny]) != -1) return 0;
        x = nx, y = ny;
    }
}

int main() {
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf(" %c", &a[i][j]);
        }
    }
    long long ans = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] == '.') continue;
            if (search(i, j, d(a[i][j]))) {
                int flag = 0;
                for (int k = 0; k < 4; k++) {
                    if (d(a[i][j]) == k) continue;
                    if (!search(i, j, k)) {
                        flag = 1;
                        switch (k) {
                            case 0: a[i][j] = 'U'; break;
                            case 1: a[i][j] = 'D'; break;
                            case 2: a[i][j] = 'L'; break;
                            case 3: a[i][j] = 'R'; break;
                        }
                        break;
                    }
                }
                if (!flag) {
                    puts("-1");
                    return 0;
                }
                ans++;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}