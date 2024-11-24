#pragma GCC optimize("Ofast,no-stack-protector")
#include <stdio.h>
#include <stdlib.h>
int a[720][720];
int n, m, d;
long long search(int x, int y, int d) {
    long long v = 0;
    for (int i = x - d; i <= x + d; i++) {
        for (int j = y - d; j <= y + d; j++) {
            if (abs(i - x) + abs(j - y) > d) continue;
            v += a[i][j];
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