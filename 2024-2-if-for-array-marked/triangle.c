#include <stdio.h>

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a + b <= c) puts("not triangle");
    else if (a == b && b == c) puts("equilateral triangle");
    else if (a * a + b * b == c * c) puts("right triangle");
    else if (a * a + b * b > c * c) {
        printf("acute ");
        if (a == b || b == c || a == c) puts("isosceles triangle");
        else puts("triangle");
    }
    else {
        printf("obtuse ");
        if (a == b || b == c || a == c) puts("isosceles triangle");
        else puts("triangle");
    }
    return 0;
}
