#include <stdio.h>
#include <string.h>

int main() {
    char s[114514];
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++)
        if (s[i] == '?') s[i] = s[n - i - 1];
    printf("%s", s);
}
