#include <stdio.h>
#include <string.h>
char s[100005];
char stk[100005];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        int top = 0;
        int flag = 1;
        for (int i = 0; i < strlen(s) && flag; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') stk[top++] = s[i];
            else {
                if (s[i] == ')' && top > 0 && stk[top - 1] == '(') top--;
                else if (s[i] == ']' && top > 0 && stk[top - 1] == '[') top--;
                else if (s[i] == '}' && top > 0 && stk[top - 1] == '{') top--;
                else flag = 0;
            }
        }
        if (top == 0 && flag) puts("True");
        else puts("False");
    }
    return 0;
}