#include <stdio.h>

int main() {
    int a, b;
    scanf("%d:%d", &a, &b);
    if (a == 0) printf("00:%02d a.m.\n", b);
    else if (a == 12) printf("12:%02d p.m.\n", b);
    else if (a > 12) printf("%02d:%02d p.m.\n", a - 12, b);
    else printf("%02d:%02d a.m.\n", a, b);
    return 0;
}