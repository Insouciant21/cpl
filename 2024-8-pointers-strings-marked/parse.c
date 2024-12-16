#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arg[1145];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    char *ex = calloc(130, sizeof(char));
    scanf("%s", ex);
    for (char *p = ex; *p; p++) {
        if (*p != ':') arg[*p] = *(p + 1) == ':' ? 1 : -1;
    }
    char *s = calloc(1500, sizeof(char));
    char *name = calloc(1500, sizeof(char));
    char *ans = calloc(114514, sizeof(char));
    int pos = 0;
    scanf("%s", name);
    sprintf(ans, "%s\n", name);
    pos = strlen(name) + 1;
    while (~scanf("%s", s)) {
        if (*s != '-') continue;
        char op = *(s + 1);
        if (arg[op] == 0) {
            sprintf(ans, "%s: invalid option -- '%c'\n", name, op);
            break;
        }
        if (arg[op] == 1) {
            char *argu = calloc(1500, sizeof(char));
            if (!~scanf("%s", argu)) {
                sprintf(ans, "%s: option requires an argument -- '%c'\n", name, op);
                break;
            }
            sprintf(ans + pos, "%c=%s\n", op, argu);
            pos += strlen(ans+pos) ;
        } else {
            sprintf(ans + pos, "%c\n", op);
            pos += 2;
        }
    }
    printf("%s", ans);
    free(s), free(ex);
    return 0;
}