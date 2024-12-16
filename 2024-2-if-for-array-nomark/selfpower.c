#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char p[100];
    scanf("%s", p);
    int s = atoi(p), q = 0, z = strlen(p);
    if (s == 0) {
        puts("0");
        return 0;
    }
    for (int i = 0; i < z; i++) q += pow(p[i] - '0', z);
    if (q == s) printf("%d", z);
    else printf("0");
    return 0;
}
