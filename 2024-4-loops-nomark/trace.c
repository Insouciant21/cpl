#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int n;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(void) {
    int a[150][150];
    bool visited[150][150];
    memset(a, 0, sizeof a);
    memset(visited, 0, sizeof visited);
    int n, m, x, y, cnt = 0;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    x--, y--;
    for (int i = 0; i < n; i++) {
        char s[150];
        scanf("%s", s);
        for (int j = 0; j < m; j++) {
            if (s[j] == '#') {
                a[i][j] = 1, cnt++;
            }
        }
    }
    printf("%d\n", cnt);
    while (cnt) {
        printf("%d %d\n", x + 1, y + 1);
        cnt--;
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (visited[nx][ny]) continue;
            if (a[nx][ny] == 0) continue;
            x = nx, y = ny;
            break;
        }
    }
}
