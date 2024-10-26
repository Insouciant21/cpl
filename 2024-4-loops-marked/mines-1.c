#include <stdio.h>
#include <string.h>

char a[150][150];
int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
int n;

int count(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (a[nx][ny] == '*') cnt++;
    }
    return cnt;
}

int main() {
    memset(a, 0, sizeof a);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%s", &a[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == 'o') a[i][j] = count(i, j) + '0';
    for (int i = 0; i < n; i++) printf("%s\n", a[i]);
}
