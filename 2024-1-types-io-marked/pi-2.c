#include <stdio.h>
#include <math.h>

int main(void) {
    double k = 236674.0 + 30303 * sqrt(61);
    double pi = log(5280.0 * 5280 * 5280 * k * k * k + 74) / sqrt(427);
    printf("%.15lf\n", pi);
    pi = 4 * (6 * atan(1.0 / 8) + 2 * atan(1.0 / 57) + atan(1.0 / 239));
    printf("%.15lf\n", pi);
    return 0;
}