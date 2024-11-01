#include <stdio.h>

int main() {
    int n, arr[2500], m = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", arr + i);
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > arr[i + 1]) m++;
        else break;
    }
    int pk = arr[n - m - 1], min = 0x3f3f3f3f, index = -1;
    for (int i = n - m; i < n; i++) {
        if (arr[i] > pk && arr[i] < min) {
            min = arr[i], index = i;
        }
    }
    int temp = arr[index];
    arr[index] = arr[n - m - 1];
    arr[n - m - 1] = temp;
    for (int i = 0; i < n - m; i++) printf("%d ", arr[i]);
    for (int i = n - 1; i >= n - m; i--) printf("%d ", arr[i]);
}