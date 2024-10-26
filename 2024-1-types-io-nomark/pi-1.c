#include <stdio.h>
#include <math.h>

int main(void) {
    double a = 4 * (4 * atan(0.2) - atan(1.0 / 239));
    double b = log(640320.0 * 640320 * 640320 + 744) / sqrt(163);
    printf("%.15lf\n", a);
    printf("%.15lf\n", b);
    return 0;
}