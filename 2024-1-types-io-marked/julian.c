#include <stdio.h>

int main(void) {
    int y, m, d;
    scanf("%d %d %d", &y, &m, &d);
    long long a = 0, p = 0, z = 0, jdn = 0;
    a = (14 - m) / 12;
    p = y + 4800 - a;
    z = m + 12 * a - 3;
    jdn = d + (153 * z + 2) / 5 + 365 * p + p / 4 - p / 100 + p / 400 - 32045;
    printf("%lld\n", jdn);
    return 0;
}