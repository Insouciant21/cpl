#include <stdio.h>
char map[101][101];

typedef struct Point {
    int x, y;
} Point;

int r, c;

int p(Point p1, Point p2) {
    p1.x++, p2.x++;
    while ( p1.y != p2.y - 1) {
        p1.x++, p2.x++, p1.y++, p2.y--;
        if (p1.x >= r || p2.x >= r || p1.y >= c || p2.y < 0) return 0;
        if (map[p1.x][p1.y] != '\\' || map[p2.x][p2.y] != '/') return 0;
    }
    return 1;
}

long long search(int x, int y) {
    Point p1 = (Point){x, y}, p2 = (Point){x, y + 1};
    long long ans = 0;
    while (1) {
        if (map[p1.x][p1.y] != '/' || map[p2.x][p2.y] != '\\') return ans;
        if (p1.x + 1 >= r || p2.x + 1 >= r || p1.y >= c || p2.y < 0) return ans;
        if (map[p1.x + 1][p1.y] == '\\' && map[p2.x + 1][p2.y] == '/')
            ans += p(p1, p2);
        p1.x++, p2.x++;
        p1.y--, p2.y++;
    }
}

int main() {
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++) scanf("%s", map[i]);
    long long ans = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c - 1; j++)
            if (map[i][j] == '/' && map[i][j + 1] == '\\')
                ans += search(i, j);
    printf("%lld\n", ans);
}