#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b) {
    return a < b ? a : b;
}
int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        char *s1 = calloc(1005, sizeof(char));
        char *s2 = calloc(1005, sizeof(char));
        scanf("%s", s1);
        scanf("%s", s2);
        for (int i = min(strlen(s1), strlen(s2)); i >= 0; i--) {
            int pos1 = strlen(s1) - i, flag = 1;
            for (int j = 0; j < i; j++) {
                if (*(s1 + pos1 + j) != *(s2 + j)) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                printf("%s%s\n", s1, s2 + i);
                break;
            }
        }
    }
    return 0;
}
