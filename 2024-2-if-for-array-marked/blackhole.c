#include <stdio.h>
#include <stdlib.h>

int cmp1(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n, sum = 0;
    scanf("%d", &n);
    while (n != 495) {
        int a[] = {n % 10, n / 10 % 10, (n / 100)};
        qsort(a, 3, sizeof(int), cmp1);
        const int c = a[0] * 100 + a[1] * 10 + a[2], d = a[2] * 100 + a[1] * 10 + a[0];
        int p = d - c;
        if (n - p > 0) sum += n - p;
        n = p;
    }
    printf("%d", sum);
    return 0;
}
