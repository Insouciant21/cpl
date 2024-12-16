#include <stdio.h>

const int MAX = (int)1e7 + 7;

int main() {
    int n, p;
    char l[MAX];
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) l[i] = getchar();
    scanf("%d", &p);
    for (int i = p - 1; i >= 0; i--) printf("%c", l[i]);
    for (int i = n - 1; i >= p; i--) printf("%c", l[i]);
    return 0;
}
