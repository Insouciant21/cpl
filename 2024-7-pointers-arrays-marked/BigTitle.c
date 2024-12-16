#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *s = malloc(114514);
    fgets(s, 114514, stdin);
    for (int i = 0, c = 0; i < strlen(s); i++) {
        char p = *(s + i);
        if (p == ' ') {
            c = 0;
            putchar(' ');
            continue;
        }
        if (!c) putchar(toupper(p));
        else putchar(tolower(p));
        c = 1;
    }
    free(s);
    return 0;
}