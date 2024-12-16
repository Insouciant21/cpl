#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        char s[114514] = {0};
        scanf("%s", s);
        int flag = 0;
        for (int i = 0; i < strlen(s); i++) {
            if (!(s[i] == '0' || s[i] == '1' || s[i] == 'z' || s[i] == 'Z')) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            puts("Radix Error");
            continue;
        }
        int ans = 0;
        for (int i = strlen(s) - 1, t = 1; i >= 0; i--, t *= 3) {
            int p = isalpha(s[i]) ? -1 : (s[i] - '0');
            ans += p * t;
        }
        printf("%d\n", ans);
    }
}
