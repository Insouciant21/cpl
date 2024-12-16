#include <stdio.h>
#include <string.h>
char s[100][100];

void paintFront(int x, int y, int a, int c) {
    for (int i = x; i <= x + 2 * c; i++) {
        for (int j = y; j <= y + 2 * a; j++) {
            if ((i - x) & 1) s[i][j] = j & 1 ? '|' : ' ';
            else s[i][j] = j & 1 ? '+' : '-';
        }
    }
}

typedef struct Point {
    int x, y;
    int ctx, cty;
} Point;

int vis[100][100];
Point q[191981];

void paintUpper(int x, int y, int a, int b) {
    int dy[] = {2, 2};
    int dx[] = {-2, 0};
    int l = 0, r = 0;
    q[r++] = (Point){x, y, 0, 0};
    vis[x][y] = 1;
    while (l < r) {
        Point p = q[l++];
        s[p.x][p.y] = '+';
        for (int i = 0; i < 2; i++) {
            int nx = p.x + dx[i], ny = p.y + dy[i];
            if (p.ctx == a || (p.cty == b && i == 0)) continue;
            s[p.x + dx[i] / 2][p.y + dy[i] / 2] = i ? '-' : '/';
            s[nx][ny] = '+';
            if (vis[nx][ny]) continue;
            q[r++] = (Point){nx, ny, p.ctx + i, p.cty + 1 - i};
            vis[nx][ny] = 1;
        }
    }
}

void paintRight(int x, int y, int b, int c) {
    int dy[] = {0, 2};
    int dx[] = {2, -2}; // 0 down 1 right
    int l = 0, r = 0;
    memset(vis, 0, sizeof vis);
    q[r++] = (Point){x, y, 0, 0};
    vis[x][y] = 1;
    while (l < r) {
        Point p = q[l++];
        s[p.x][p.y] = '+';
        for (int i = 0; i < 2; i++) {
            int nx = p.x + dx[i], ny = p.y + dy[i];
            if ((p.ctx == b && i) || (p.cty == c && !i)) continue;
            s[p.x + dx[i] / 2][p.y + dy[i] / 2] = i ? '/' : '|';
            s[nx][ny] = '+';
            if (vis[nx][ny]) continue;
            q[r++] = (Point){nx, ny, p.ctx + i, p.cty + 1 - i};
            vis[nx][ny] = 1;
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        memset(s, ' ', sizeof(s));
        int x = 2 * b + 1, y = 1;
        paintFront(x, y, a, c);
        paintUpper(x, y, a, b);
        paintRight(x, y + 2 * a, b, c);
        for (int i = 1; i <= 2 * b + 1 + 2 * c; i++) {
            for (int j = 1; j <= 2 * b + 1 + 2 * a; j++) {
                printf("%c", s[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}