#include <stdio.h>
#include <string.h>
char a[30][30];
int dx[] = {0, 1, 1, 1};
int dy[] = {1, 0, 1, -1};

int win(int x, int y, char type) {
    for (int d = 0; d < 4; d++) {
        int l = 0, r = 0;
        int nx = x - dx[d], ny = y - dy[d];
        while (1) {
            if (nx < 0 || ny < 0 || nx >= 20 || ny >= 20) break;
            if (a[nx][ny] != type) break;
            nx -= dx[d], ny -= dy[d], l++;
        }
        nx = x + dx[d], ny = y + dy[d];
        while (1) {
            if (nx < 0 || ny < 0 || nx >= 20 || ny >= 20) break;
            if (a[nx][ny] != type) break;
            r++, nx += dx[d], ny += dy[d];
        }
        if (l + r >= 4) return 1;
    }
    return 0;
}

int whiteWin() {
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            if (a[i][j] == '_')
                if (win(i, j, '*')) return 1;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (a[i][j] == '_') {
                if (win(i, j, '#')) {
                    a[i][j] = '*';
                    return 0;
                }
            }
        }
    }
    return 0;
}

int blackWin() {
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            if (a[i][j] == '_')
                if (win(i, j, '#')) return 1;
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(a, 0, sizeof a);
        for (int i = 0; i < 20; i++) scanf("%s", a[i]);
        if (whiteWin())
            puts("Lose");
        else if (blackWin())
            puts("Win");
        else
            puts("Not Sure");
    }
}