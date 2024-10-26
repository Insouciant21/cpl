#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char s[114514], t[114514];
    scanf("%s", &s);
    int len = strlen(s);
    while (n--) {
        for (int i = 0; i < strlen(s); i++) {
            int A = 0, B = 0, dot = 0;
            for (int j = i - 3; j <= i + 3; j++) {
                if (j >= 0 && j < strlen(s) && j != i) {
                    if (s[j] == 'A') A++;
                    else if (s[j] == 'B') B++;
                    else dot++;
                }
            }
            if (s[i] == '.') {
                if (A == 0 ^ B == 0) {
                    if (2 <= A && A <= 4) t[i] = 'A';
                    if (2 <= B && B <= 4) t[i] = 'B';
                }
                else t[i] = '.';
            }
            if (s[i] == 'A' && (B || A >= 5 || A <= 1)) t[i] = '.';
            if (s[i] == 'B' && (A || B >= 5 || B <= 1)) t[i] = '.';
            if (t[i] == '\0') t[i] = s[i];
        }
        strncpy(s, t, len);
        memset(t, 0, sizeof t);
    }
    printf("%s", s);
    return 0;
}