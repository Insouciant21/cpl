#include <stdio.h>

int main() {
    int x;
    scanf("%x", &x);
    unsigned *p = (unsigned *)&x;
    float *q = (float *)&x;
    printf("%d\n%u\n%.6f\n%.3e\n", x, *p, *q, *q);
}
