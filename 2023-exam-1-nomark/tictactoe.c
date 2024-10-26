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
                int m = -1, p = -1, q = -1, r = -1;
                for (int k = 0; k < x; k++) {
                    m &= arr[i][k + j] * (k + j < n), p &= arr[k + i][j] * (k + i < n);
                    q &= arr[k + i][k + j] * (k + i < n && k + j < n);
                    r &= arr[i - k][j + k] * (i - k >= 0 && j + k < n);
                }
                if (m == arr[i][j] || p == arr[i][j] || q == arr[i][j] || r == arr[i][j]) vic[arr[i][j]] = 1;
            }
        }

        if (!vic[1] && vic[2] && !vic[4]) puts("2");
        else if (vic[1] && !vic[2] && !vic[4]) puts("1");
        else if (!vic[1] && !vic[2] && vic[4]) puts("4");
        else puts("draw");
    }
}