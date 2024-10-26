#include<stdio.h>

int main(void) {
    double p, l, t;
    scanf("%lf %lf %lf", &p, &l, &t);
    const double R = 8.314;
    printf("%.4e\n", p * l / R * l / t * l);
    return 0;
}