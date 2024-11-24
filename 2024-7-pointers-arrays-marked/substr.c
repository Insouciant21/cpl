#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 114514
int main() {
    char *s = malloc(MAXLEN), *t = malloc(MAXLEN);
    scanf("%s%s", s, t);
    int n = strlen(s), m = strlen(t);
    int *f = calloc(MAXLEN, sizeof(int));
    *(f + 0) = *(f + 1) = 0;
    for (int i = 1; i < m; i++) {
        int j = *(f + i);
        while (j && *(t + i) != *(t + j)) j = *(f + j);
        *(f + i + 1) = *(t + i) == *(t + j) ? j + 1 : 0;
    }
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j && *(s + i) != *(t + j)) j = *(f + j);
        if (*(s + i) == *(t + j)) j++;
        if (j == m) printf("%d ", i - m + 1);
    }
    free(s), free(t), free(f);
    return 0;
}