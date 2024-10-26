#include <stdio.h>
#include <stdlib.h>

int main() {
    char res[10];
    long long l = 0, r = 1LL << 32;
    long long guess = (l + r) >> 1;
    while (1) {
        printf("%lld\n", guess);
        fflush(stdout);
        scanf("%s", res);
        switch (res[0]) {
            case 'G':
                r = guess;
                guess = (l + r) >> 1;
                break;
            case 'L':
                l = guess;
                guess = (l + r) >> 1;
                break;
            case 'E': return 0;
            case 'O': return 0;
        }
    }
}
