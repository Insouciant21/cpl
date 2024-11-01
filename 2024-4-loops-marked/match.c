#include <stdio.h>
#include <string.h>
int a[600][600], s[130000];
typedef struct Node {
    int x, y;
} Node;
Node p[130000][2];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            p[a[i][j]][s[a[i][j]]++] = (Node) {i, j};
        }
    }
    for (int i = 1; i <= n * m / 2; i++) {
        for (int d = 0; d < 4; d++) {
            Node x = p[i][0], y = p[i][1];
            int flag = 0;
            while (1) {
                Node nx = (Node) {x.x + dx[d], x.y + dy[d]}, ny = (Node) {y.x + dx[d], y.y + dy[d]};
                if ((nx.x < 0 || nx.x >= n || nx.y < 0 || nx.y >= m) &&
                    (ny.x < 0 || ny.x >= n || ny.y < 0 || ny.y >= m)) {
                    flag = 1;
                    break;
                }
                if (((nx.x >= 0 && nx.x < n && nx.y >= 0 && nx.y < m) && a[nx.x][nx.y] != 0) ||
                    ((ny.x >= 0 && ny.x < n && ny.y >= 0 && ny.y < m) && a[ny.x][ny.y] != 0))
                    break;
                x = nx, y = ny;
            }
            if (flag) {
                a[p[i][0].x][p[i][0].y] = a[p[i][1].x][p[i][1].y] = 0;
                printf("%d ", i);
                break;
            }
        }
    }
}
