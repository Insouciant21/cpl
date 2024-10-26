#include <math.h>
#include <stdio.h>

int main(void) {
    double p, q;
    scanf("%lf %lf", &p, &q);
    double ans = cbrt(-q / 2 + sqrt(q * q / 4 + p * p * p / 27)) + cbrt(-q / 2 - sqrt(q * q / 4 + p * p * p / 27));
    printf("%.3lf\n", ans);
}