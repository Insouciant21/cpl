#include <stdio.h>
#include <string.h>

void reverse(char *s) {
    int l = 0, r = strlen(s) - 1;
    while (l < r) {
        char t = s[l];
        s[l] = s[r];
        s[r] = t;
        l++;
        r--;
    }
}

int main() {
    char a[10600] = {0}, b[10600] = {0};
    while (~scanf("%s %s", a, b)) {
        reverse(a), reverse(b);
        int c[10600] = {0};
        memset(c, 0, sizeof c);
        int g = (strlen(a) > strlen(b) ? strlen(a) : strlen(b));
        for (int i = 0; i < g; i++) {
            if (a[i] == 0) a[i] += '0';
            if (b[i] == 0) b[i] += '0';
            c[i] += (a[i] - '0') + (b[i] - '0');
            if (c[i] >= 10) {
                c[i] -= 10;
                c[i + 1]++;
            }
        }
        int p = 0;
        for (int i = 10590; i >= 0; i--) {
            if (c[i] != 0) {
                p = i;
                break;
            }
        }
        for (int i = p; i >= 0; i--) printf("%d", c[i]);
        printf("\n");
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        memset(c, 0, sizeof c);
    }
}
