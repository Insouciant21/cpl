#include <stdio.h>
int a[11][11];

int checkArea(int stx, int sty, int edx, int edy) {
    int sum = 0, mul = 1, xor = 0;
    for (int i = stx; i <= edx; i++)
        for (int j = sty; j <= edy; j++) sum += a[i][j], mul *= a[i][j], xor ^= a[i][j];
    return (sum == 45 && mul == 362880 && xor == 1);
}

int main() {
    int flag = 1;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) scanf("%d", &a[i][j]);
    for (int i = 0; i < 9; i++)
        if (checkArea(i, 0, i, 8) == 0 || checkArea(0, i, 8, i) == 0) flag = 0;
    for (int i = 0; i < 9; i += 3)
        for (int j = 0; j < 9; j += 3)
            if (checkArea(i, j, i + 2, j + 2) == 0) flag = 0;
    printf(flag ? "YES\n" : "NO\n");
}