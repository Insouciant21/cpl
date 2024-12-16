#include <stdio.h>

int leap(const unsigned long long p) {
    return (p % 4 == 0 && p % 100 != 0) || (p % 400 == 0);
}

int main() {
    unsigned long long a, b;
    scanf("%llu %llu", &a, &b);
    if (leap(a)) printf("Leap year!\n");
    else printf("Normal year!\n");
    if (leap(a + b)) printf("Leap year!\n");
    else printf("Normal year!\n");
    return 0;
}