#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {
    int a, b;
    char x[4];
    while (~scanf("%d %s %d", &a, x, &b)) {
        if (strlen(x) == 1) {
            if (x[0] == '+') printf("%d\n", a + b);
            if (x[0] == '-') printf("%d\n", a - b);
            if (x[0] == '*') printf("%d\n", a * b);
            if (x[0] == '/') printf("%d\n", a / b);
            if (x[0] == '%') printf("%d\n", a % b);
        }
        else {
            if (x[0] == '*') printf("%.0f\n", pow(a, b));
            else if (x[0] == '/') printf("%.3lf\n", (double)a / b);
        }
    }
}
