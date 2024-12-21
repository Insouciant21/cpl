#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ternaryToDex() {
    char s[10005] = { 0 };
    scanf("%s", s);
    int flag = 0;
    size_t len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (!(s[i] == '0' || s[i] == '1' || s[i] == 'z' || s[i] == 'Z')) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        puts("Radix Error");
        return;
    }
    int ans = 0;
    for (int i = strlen(s) - 1, t = 1; i >= 0; i--, t *= 3) {
        int p = isalpha(s[i]) ? -1 : s[i] - '0';
        ans += p * t;
    }
    printf("%d %s\n", ans, s);
}

void dexToTernary()
{
    char s[10005] = { 0 }, p[10005] = { 0 };
    scanf("%s", s);
    char* endpoint = NULL;
    long dec = strtol(s, &endpoint, 10);
    if (*endpoint) {
        puts("Radix Error");
        return;
    }
    int pos = 0, sign = 0;
    int tmp = dec;
    if (dec == 0) {
        puts("0 0");
        return;
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
    printf("%d ", tmp);
    for (int i = strlen(p) - 1; i >= 0; i--)
        printf("%c", p[i]);
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--)
    {
        char op[2];
        scanf("%s", op);
        if (op[0] == 't') ternaryToDex();
        else dexToTernary();
    }
}