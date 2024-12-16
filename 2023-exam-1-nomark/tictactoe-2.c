#include <stdio.h>

int main() {
    int T, x;
    scanf("%d %d", &T, &x);
    while (T--) {
        int n, arr[20][20] = {0}, vic[6] = {0};
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) scanf("%d", &arr[i][j]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!arr[i][j]) continue;
                int m = 0, p = 0, q = 0, r = 0;
                for (int k = 0; k < x; k++) {
                    if (arr[i][k + j] * (k + j < n) != arr[i][j]) m = 1;
                    if (arr[k + i][j] * (k + i < n) != arr[i][j]) p = 1;
                    if (arr[k + i][k + j] * (k + i < n && k + j < n) != arr[i][j]) q = 1;
                    if (arr[i - k][j + k] * (i - k >= 0 && j + k < n) != arr[i][j]) r = 1;
                }
                if (m + p + q + r != 4) vic[arr[i][j]] = 1;
            }
        }

        if (!vic[1] && vic[2] && !vic[4]) puts("2");
        else if (vic[1] && !vic[2] && !vic[4]) puts("1");
        else if (!vic[1] && !vic[2] && vic[4]) puts("4");
        else puts("draw");
    }
}