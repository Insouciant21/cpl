#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mode(char *p, char *ans) {
    char *s[] = {"const", "int", "float", "double", "long", "static", "void", "char",
                 "extern", "return", "break", "enum", "struct", "typedef", "union", "goto"};
    for (int i = 0; i < 16; i++)
        if (strcmp(p, s[i]) == 0) {
            strcat(ans, "reserved ");
            return 0;
        }
    int flag = 1, dot = 0, num = 0;
    for (int i = 0; i < strlen(p); i++) {
        if (!isdigit(p[i])) flag = 0;
        if (p[i] == '.') dot++;
        if (isdigit(p[i])) num++;
    }
    if (flag) {
        strcat(ans, "integer ");
        return 1;
    }
    char *sign[] = {"+", "-", "*", "/", "=", "==", "!=", ">=", "<=", ">", "<"};
    for (int i = 0; i < 11; i++)
        if (strcmp(p, sign[i]) == 0) {
            strcat(ans, "operator ");
            return 2;
        }
    if (!flag && dot == 1 && num) {
        strcat(ans, "float ");
        return 3;
    }
    if (p[0] == '_' || isalpha(p[0])) {
        strcat(ans, "variable ");
        return 4;
    }
    return 5;
}

int main() {
    char *ans = calloc(500000, sizeof(char));
    while (1) {
        char *p = calloc(5000, sizeof(char));
        char *sentence = calloc(5000, sizeof(char));
        int c = 0;
        if (scanf(" %[^;]", sentence) == EOF) break;
        if (getchar() != ';') {
            printf("Compile Error\n");
            return 0;
        }
        while ((sentence[c] == ' ' || sentence[c] == '\n') && sentence[c] != '\0') c++;
        while (~sscanf(sentence + c, "%s", p)) {
            if (mode(p, ans) == 5) {
                printf("Compile Error\n");
                return 0;
            }
            c += strlen(p);
            while ((sentence[c] == ' ' || sentence[c] == '\n') && sentence[c] != '\0') c++;
        }
        strcat(ans, "\n");
        free(p), free(sentence);
    }
    printf("%s", ans);
}