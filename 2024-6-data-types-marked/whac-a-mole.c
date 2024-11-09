#include <stdio.h>
int a[911][911];
int n, m, d;
typedef struct Stage {
    int x, y;
    int step;
} Stage;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int vis[911][911];
long long search(int x, int y, int d) {
    Stage q[6110];
    int l = 0, r = 0;
    long long v = 0;
    q[r++] = (Stage) {x, y, 0};
    vis[x][y] = 1;
    while (l < r) {
        Stage prs = q[l++];
        v += a[prs.x][prs.y];
        if (prs.step == d) continue;
        for (int i = 0; i < 4; i++) {
            int nx = prs.x + dx[i];
            int ny = prs.y + dy[i];
            if (nx >= 60 && nx < n + 60 && ny >= 60 && ny < m + 60 && !vis[nx][ny]) {
                q[r++] = (Stage) {nx, ny, prs.step + 1};
                vis[nx][ny] = 1;
            }
        }
    }
    return v;
}
int ans[114514];
int main() {
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 60; i < n + 60; i++)
        for (int j = 60; j < m + 60; j++) scanf("%d", &a[i][j]);
    int x = 60, y = 60;
    long long v = search(x, y, d);
    long long maxV = v;
    int top = 0;
    ans[top++] = 0;
    while (1) {
        int relativeX = x - 60, relativeY = y - 60;
        if (!(relativeX & 1) && relativeY != m - 1) {
            int sx = x - d, sy = y;
            while (sx != x) v -= a[sx][sy], sx++, sy--;
            while (sy != y) v -= a[sx][sy], sx++, sy++;
            v -= a[sx][sy];
            sx = x - d, sy = ++y;
            while (sx != x) v += a[sx][sy], sx++, sy++;
            while (sy != y) v += a[sx][sy], sx++, sy--;
            v += a[sx][sy];
        }
        else if (relativeX & 1 && relativeY != 0) {
            int sx = x - d, sy = y;
            while (sx != x) v -= a[sx][sy], sx++, sy++;
            while (sy != y) v -= a[sx][sy], sx++, sy--;
            v -= a[sx][sy];
            sx = x - d, sy = --y;
            while (sx != x) v += a[sx][sy], sx++, sy--;
            while (sy != y ) v += a[sx][sy], sx++, sy++;
            v += a[sx][sy];
        }
        else {
            int sy = y - d, sx = x;
            while (sy != y) v -= a[sx][sy], sx--, sy++;
            while (sx != x) v -= a[sx][sy], sx++, sy++;
            v -= a[sx][sy];
            sy = y - d, sx = ++x;
            while (sy != y) v += a[sx][sy], sx++, sy++;
            while (sx != x) v += a[sx][sy], sx--, sy++;
            v += a[sx][sy];
        }
        relativeX = x - 60, relativeY = y - 60;
        if (v > maxV) {
            maxV = v, top = 0;
            ans[top++] = relativeX * 1000 + relativeY;
        }
        else if (v == maxV) ans[top++] = relativeX * 1000 + relativeY;
        if (relativeX == n - 1 && relativeY == (n & 1 ? m - 1 : 0)) break;
    }
    printf("%lld %d\n", maxV, top);
    for (int i = 0; i < top; i++) printf("%d %d\n", ans[i] / 1000 + 1, ans[i] % 1000 + 1);
}