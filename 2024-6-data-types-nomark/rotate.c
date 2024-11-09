#include <stdio.h>
#include <string.h>
#define swap(a, b) { int t = a;a = b;b = t;}

int main() {
    int a, b, c; // a x b y c z
    int x = 0, y = 0;
    char s[2000];
    scanf("%d%d%d", &a, &b, &c);
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++) {
        switch (s[i]) {
            case 'W': {
                x -= c;
                swap(a, c);
                break;
            }
            case 'S': {
                x += a;
                swap(a, c);
                break;
            }
            case 'A': {
                y -= c;
                swap(b, c);
                break;
            }
            case 'D': {
                y += b;
                swap(b, c);
                break;
            }
        }
    }
    printf("%d %d %d %d\n", x, x + a, y, y + b);
    return 0;
}