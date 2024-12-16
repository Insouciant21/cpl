#include <stdio.h>
int a[1001000];
#define swap(a, b)                                                                                                     \
    {                                                                                                                  \
        int t = a;                                                                                                     \
        (a) = b;                                                                                                         \
        (b) = t;                                                                                                         \
    }

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    int l = 0, r = n - 1;
    int mid = a[k - 1];
    while (l < r) {
        while (a[l] < mid && l < r) l++;
        while (a[r] >= mid && l < r) r--;
        if (l != r) swap(a[l], a[r]);
    }
    int px = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == mid) {
            px = i;
            break;
        }
    }
    if (a[l] >= mid && l == r && a[r] >= mid) swap(a[l], a[px]);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
}
