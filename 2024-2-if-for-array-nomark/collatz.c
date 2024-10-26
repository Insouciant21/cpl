#include <math.h>
#include <stdio.h>

int n = -1, max = -1;
void collatz(int s) {
    n++;
    max = max > s ? max : s;
    if (s != 1) collatz(s % 2 ? 3 * s + 1 : s / 2);
}

int main() {
    int b;
    scanf("%d", &b);
    collatz(b);
    printf("%d %d\n", n, max);
    return 0;
}
