#include <stdio.h>
char map[601][601][601];
int n;
int dx[6] = {-1, 0, 0, 0, 0, 1};
int dy[6] = {0, -1, 0, 0, 1, 0};
int dz[6] = {0, 0, -1, 1, 0, 0};
int search(int x, int y, int z) {
    int ret = 0;
    for (int i = 0; i < 6; i++) {
        int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && nz >= 0 && nz < n && map[nx][ny][nz] == '*') {
            ret++;
        }
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    getchar();
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                map[i][j][k] = getchar();
                if (map[i][j][k] == '?') {
                    x = i, y = j, z = k;
                }
            }
        }
    }
    map[x][y][z] = search(x, y, z) + '0';
    int flag = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (map[i][j][k] == '*') continue;
                if (search(i, j, k) + '0' != map[i][j][k]) {
                    flag = 0;
                    break;
                }
            }
            if (!flag) break;
        }
        if (!flag) break;
    }
    if (flag) {
        puts("valid");
        putchar(map[x][y][z]);
        return 0;
    }
    map[x][y][z] = '*';
    flag = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (map[i][j][k] == '*') continue;
                if (search(i, j, k) + '0' != map[i][j][k]) {
                    if (flag) puts("invalid");
                    printf("%d %d %d\n", i + 1, j + 1, k + 1);
                    flag = 0;
                    break;
                }
            }
        }
    }
    if (flag) {
        puts("valid");
        putchar('*');
    }
}