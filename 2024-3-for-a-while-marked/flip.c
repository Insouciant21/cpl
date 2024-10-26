#include <stdio.h>
#include <string.h>

int main() {
    int s[114514];
    int n;
    scanf("%d", &n);
    memset(s, 0, sizeof s);
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i) s[j] = s[j] ^ 1;
    for (int i = 1; i <= n; i++)
        if (s[i]) printf("%d ", i);
}
