#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    int len, n, base = 1, p = 0;
    char s[60];
    scanf("%d %d %s", &len, &n, s);
    for (int i = 0; i < strlen(s); i++) {
        if (isdigit(s[i]) && s[i] - '0' >= n || (!isdigit(s[i]) && s[i] - 'A' + 10 >= n)) {
            puts("Error");
            return 0;
        }
    }
    for (int i = strlen(s) - 1; i >= 0; i--) p += base * (isdigit(s[i]) ? s[i] - '0' : s[i] - 'A' + 10), base *= n;
    printf("%d\n", p);
}
