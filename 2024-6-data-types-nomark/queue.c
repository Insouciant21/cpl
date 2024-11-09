#include <stdio.h>
int q[1919810];

int main() {
    int l = 0, r = 0;
    int n;
    scanf("%d", &n);
    while (n--) {
        char op[10];
        int c;
        scanf("%s", op);
        switch (op[0]) {
            case 'I': {
                scanf(" %d", &c);
                q[r++] = c;
                break;
            }
            case 'O': {
                printf("%d\n", q[l]);
                q[l++] = 0;
                break;
            }
            case 'C': {
                printf("%d [", r - l);
                for (int i = l; i < r; i++) printf(i == l ? "%d" : ",%d", q[i]);
                puts("]");
                break;
            }
        }
    }
    return 0;
}