#include <ctype.h>
#include <stdio.h>
#include <string.h>
char s[1919810];

int main(void) {
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++) {
        if (isupper(s[i]) && i != 0) printf(" %c", tolower(s[i]));
        else putchar(s[i]);
    }
}