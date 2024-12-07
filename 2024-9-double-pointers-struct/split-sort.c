#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[114514], delim[55];
char p[100][200];
int pos = 0;

int strdcmp(const void *a, const void *b) {
    char *lhs = (char *)a, *rhs = (char *)b;
    for (int i = 0; i < strlen(lhs); i++) {
        if (lhs[i] != rhs[i]) return lhs[i] - rhs[i];
    }
    return 0;
}

int main() {
    scanf("%s%s", s, delim);
    char *tok = strtok(s, delim);
    while (tok != NULL) {
        strcpy(p[pos++], tok);
        tok = strtok(NULL, delim);
    }
    qsort(p, pos, sizeof(p[0]), strcmp);
    for (int i = 0; i < pos; i++) {
        printf("%s\n", p[i]);
    }
}