#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        char s[114514] = {0}, p[114514] = {0};
        scanf("%s", s);
        int flag = 0, start = s[0] == '-' ? 1 : 0;
        for (int i = start; i < strlen(s); i++) {
            if (!isdigit(s[i])) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            puts("Radix Error");
            continue;
        }
        int dec = atoi(s), pos = 0, sign = 0;
        if (dec == 0) {
            puts("0");
            continue;
        }
        if (dec < 0) sign = 1, dec = -dec;
        while (dec) {
            p[pos++] = dec % 3 + '0';
            dec /= 3;
        }
        for (int i = 0; i < pos; i++) {
            if (p[i] == '3') p[i] = '0', p[i + 1]++;
            if (p[i] == '2') p[i] = 'Z', p[i + 1]++;
        }
        if (p[pos] == 1) p[pos] = '1', p[pos + 1] = '\0';
        if (sign) {
            for (int i = 0; i < pos + 1; i++) {
                if (p[i] == '1') p[i] = 'Z';
                else if (p[i] == 'Z') p[i] = '1';
            }
        }
        for (int i = strlen(p) - 1; i >= 0; i--) printf("%c", p[i]);
        printf("\n");
    }
}