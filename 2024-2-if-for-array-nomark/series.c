#include <stdio.h>

int main() {
    double x, sum = 0;
    int n;
    scanf("%lf %d", &x, &n);
    double p = x;
    for (int i = 0; i <= n; i++) {
        sum += p / (2 * i + 1);
        p = p * x * x * -1;
    }
    printf("%.10lf", sum * 4);
    return 0;
}
