#include <ctype.h>
#include <stdio.h>

int main() {
    int len;
    scanf("%d", &len);
    char str[114514];
    scanf("%s", str);
    for (int i = len - 1; i >= 0; i--) {
        if (islower(str[i])) putchar(toupper(str[i]));
        else if (isupper(str[i])) putchar(tolower(str[i]));
        else putchar(str[i]);
    }
}