#include <stdio.h>

int main() {
    int n, k, b, l;
    scanf("%d %d %d %d", &n, &k, &b, &l);
    int life[2000];
    for (int i = 1; i <= n; i++) life[i] = l;
    int remaining = l * n;
    int pos = 1, count = 0, bullet = b;
    while (remaining != 1) {
        if (life[pos] > 0) count++;
        if (count == k) {
            if (bullet) life[pos]--, bullet--, count = 0, remaining--;
            else bullet = b, count = 0;
        }
        if (pos != n) pos++;
        else pos = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (life[i] == 1) {
            printf("%d\n", i);
            break;
        }
    }
}