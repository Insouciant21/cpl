#include <stdio.h>

int map[52][52];
// int vis[52][52];
int m, n;
int simulation(int entrance)
{
    struct Node { int x, y; } cur;
    cur.x = 0; cur.y = entrance;
    while (cur.x != m)
    {
        switch (map[cur.x][cur.y])
        {
        case 1:
            if (map[cur.x][cur.y + 1] == -1) return -1;
            if (cur.y == n - 1) return -1;
            break;
        case -1:
            if (map[cur.x][cur.y - 1] == 1) return -1;
            if (cur.y == 0) return -1;
            break;
        }
        cur.y = cur.y + map[cur.x][cur.y];
        cur.x++;
    }
    if (cur.y < 0 || cur.y >= n) return -1;
    return cur.y;
}

int main(void)
{
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &map[i][j]);
    for (int i = 0; i < n; i++)
        printf("%d ", simulation(i));
}
