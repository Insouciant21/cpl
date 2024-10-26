#include <stdio.h>

double h(double x, double a, double b) {
    return a + b * x;
}

int main(void) {
    int m;
    scanf("%d", &m);
    double x[110], y[110];
    for (int i = 0; i < m; i++) scanf("%lf%lf", x + i, y + i);
    int T = 2000;
    double alpha = 0.01, a = 1, b = 1;
    while (T--) {
        double da = 0, db = 0;
        for (int i = 0; i < m; i++) {
            da += h(x[i], a, b) - y[i];
            db += (h(x[i], a, b) - y[i]) * x[i];
        }
        da /= m, db /= m;
        a -= alpha * da;
        b -= alpha * db;
    }
    printf("y = %.3lf + %.3lfx\n", a, b);
}
