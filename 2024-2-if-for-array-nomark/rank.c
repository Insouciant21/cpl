#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    if (0 <= a && a < 60) printf("F");
    else if (60 <= a && a < 70) printf("D");
    else if (70 <= a && a < 80) printf("C");
    else if (80 <= a && a < 90) printf("B");
    else if (90 <= a && a <= 100) printf("A");
    else printf("Wrong score");
    return 0;
}