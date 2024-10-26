#include <ctype.h>
#include <stdio.h>

int main(void) {
    char p[30];
    int pre;
    double frac, factor;
    char unit;
    scanf("%s %d %lf %lf %c", p, &pre, &frac, &factor, &unit);
    printf("%.2s: %d (%.5lf) | %.5E %.5lf %c\n", p, pre, frac, pre + frac, factor * (pre + frac), toupper(unit));
    return 0;
}