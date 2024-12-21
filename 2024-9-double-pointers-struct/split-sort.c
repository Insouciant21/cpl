#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[114514], delim[55], p[100][200];
int pos = 0;
int strdcmp(const void *a, const void *b) { return strcmp((char *)a, (char *)b); }
int main() {
    scanf("%s%s", s, delim);
    char *tok = strtok(s, delim);
    while (tok != NULL) {
        strcpy(p[pos++], tok);
        tok = strtok(NULL, delim);
    }
    qsort(p, pos, sizeof(p[0]), strcmp);
    for (int i = 0; i < pos; i++) printf("%s\n", p[i]); 
}