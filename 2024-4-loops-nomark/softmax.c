#include <math.h>
#include <stdio.h>

int main(void) {
    double x[120];
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%lf", &x[i]);
    for (int i = 0; i < k; i++) {
        double t;
        scanf("%lf", &t);
        double y[120] = {0};
        double sum = 0, res = 0;
        for (int j = 0; j < n; j++) sum += exp(x[j] / t);
        for (int j = 0; j < n; j++) {
            y[j] = exp(x[j] / t) / sum;
            res += y[j];
        }
        for (int j = 0; j < n; j++) printf("%.3lf ", y[j]);
        double ey = res / n, var = 0;
        for (int j = 0; j < n; j++) var = var + (y[j] - ey) * (y[j] - ey);
        printf("%.3lf\n", var / n);
    }
}
