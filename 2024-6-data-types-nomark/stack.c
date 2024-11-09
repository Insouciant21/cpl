#include <stdio.h>
char stk[1919810];

int main() {
    int top = 0;
    char c;
    int n;
    scanf("%d", &n);
    while (n--) {
        char op[10];
        scanf("%s", op);
        switch (op[1]) {
            case 'u': {
                scanf(" %c", &c);
                stk[top++] = c;
                break;
            }
            case 'o': {
                if (op[0] == 'p') {
                    if (top != 0) stk[--top] = '\0';
                    else puts("Empty");
                }
                else {
                    if (top > 0) printf("%c\n", stk[top - 1]);
                    else puts("Empty");
                }
                break;
            }
            case 'r': {
                if (top == 0) puts("Empty");
                else {
                    for (int i = top - 1; i >= 0; i--) printf("| %c |\n", stk[i]);
                    puts("|===|");
                }
                break;
            }
        }
    }
    return 0;
}