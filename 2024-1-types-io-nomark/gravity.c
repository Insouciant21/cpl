#include<stdio.h>

int main(void) {
    const double G = 6.674 * 1e-11;
    const double M = 77.15;
    double m = 0, r = 0;
    scanf("%le %le", &m, &r);
    printf("%.3e\n", G * M * m / (r * r));
    return 0;
}