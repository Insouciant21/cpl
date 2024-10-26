#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool numList[100000001];
int prime[20000001];

int main() {
    int n, q = 0;
    scanf("%d", &n);
    int cnt = 0;
    memset(numList, 0, sizeof(numList));
    for (int i = 2; i <= n; i++) {
        if (!numList[i]) prime[cnt++] = i;
        for (int j = 0; j < cnt && i * prime[j] <= n; j++) {
            numList[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    printf("%d\n", cnt);
}
