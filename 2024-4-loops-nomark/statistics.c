#include <ctype.h>
#include <stdio.h>

int main() {
    int sz[256] = {0};
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        const char x = getchar();
        sz[x]++;
    }
    int maxN = 0, last = 0;
    for (int i = 0; i < 256; i++) {
        if (sz[i] > 0) {
            if (sz[i] > maxN) maxN = sz[i];
            if (isalpha(i) && toupper(i) > last) last = toupper(i);
        }
    }
    for (int i = maxN; i > 0; i--) {
        for (int j = 'A'; j <= 'Z'; j++) {
            if (sz[j] > 0 || sz[tolower(j)] > 0) {
                if (sz[tolower(j)] >= i) printf("=");
                else if (sz[tolower(j)] != 0) printf(" ");
                if (sz[j] >= i) printf("=");
                else if (sz[j] != 0) printf(" ");
                if (j != last) printf(" ");
            }
        }
        printf("\n");
    }
    for (int j = 'A'; j <= 'Z'; j++) {
        if (sz[j] == 0 && sz[tolower(j)] == 0) continue;
        if (sz[tolower(j)] > 0) printf("-");
        if (sz[j] > 0) printf("-");
        if (j != last) printf("-");
    }
    printf("\n");
    for (int j = 'A'; j <= 'Z'; j++) {
        if (sz[j] == 0 && sz[tolower(j)] == 0) continue;
        if (sz[tolower(j)] > 0) printf("%c", tolower(j));
        if (sz[j] > 0) printf("%c", j);
        if (j != last) printf(" ");
    }
    return 0;
}
