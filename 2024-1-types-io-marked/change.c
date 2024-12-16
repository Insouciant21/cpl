#include<stdio.h>

int main(void) {
    int x;
    int a[] = {50, 20, 10, 5, 1};
    scanf("%d", &x);
    for (int i = 0; i < 5; i++) {
        printf("%d\n", x / a[i]);
        x = x % a[i];
    }
    return 0;
}