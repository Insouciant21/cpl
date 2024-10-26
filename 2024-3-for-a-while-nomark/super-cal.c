#include <math.h>
#include <stdio.h>
#include <string.h>
const int MOD = (int)1e9;

typedef struct BigInt_ {
    int data[1200];
} BigInt;

BigInt zero = {};

BigInt add(BigInt a, BigInt b) {
    BigInt result = zero;
    for (int i = 0, carry = 0; i < 1200; i++) {
        result.data[i] = a.data[i] + b.data[i] + carry;
        carry = result.data[i] / MOD;
        result.data[i] %= MOD;
    }
    return result;
}

BigInt subtract(BigInt a, BigInt b) {
    BigInt result = zero;
    for (int i = 0, carry = 0; i < 1200; i++) {
        result.data[i] = a.data[i] - b.data[i] - carry;
        if (result.data[i] < 0) carry = 1, result.data[i] += MOD;
        else carry = 0;
    }
    return result;
}

int equal(BigInt a, BigInt b) {
    for (int i = 0; i < 1200; i++)
        if (a.data[i] != b.data[i]) return 0;
    return 1;
}

int geq(BigInt a, BigInt b) {
    for (int i = 1199; i >= 0; i--) {
        if (a.data[i] == b.data[i]) continue;
        if (a.data[i] > b.data[i]) return 1;
        return 0;
    }
    return 1;
}

BigInt BigIntFromInt(int x) {
    BigInt result = zero;
    result.data[0] = x % MOD;
    result.data[1] = x / MOD;
    return result;
}

BigInt shiftRight(BigInt bigInt) {
    BigInt result = zero;
    int carry = 0;
    for (int i = 1199; i >= 0; i--) {
        int oc = carry;
        carry = bigInt.data[i] & 1;
        result.data[i] = (bigInt.data[i] + oc * MOD) >> 1;
    }
    return result;
}

BigInt multiply(BigInt a, BigInt b) {
    BigInt result = zero;
    while (!equal(b, zero)) {
        if (b.data[0] & 1) result = add(result, a);
        a = add(a, a);
        b = shiftRight(b);
    }
    return result;
}

BigInt divide(BigInt a, BigInt b) {
    BigInt p = b, k = BigIntFromInt(1);
    int cnt = 0;
    while (geq(a, p)) p = add(p, p), cnt++, k = add(k, k);
    BigInt result = zero;
    while (cnt--) {
        p = shiftRight(p);
        k = shiftRight(k);
        if (geq(a, p)) {
            a = subtract(a, p);
            result = add(result, k);
        }
    }
    return result;
}

BigInt readBigInt() {
    BigInt bigint = zero;
    char t[12000];
    scanf("%s", t);
    int len = strlen(t);
    for (int i = 0; i < len; i++) bigint.data[i / 9] += (t[len - i - 1] - '0') * (int)pow(10, i % 9);
    return bigint;
}

void writeBigInt(BigInt bigInt) {
    int i = 1199;
    for (; i > 0; i--)
        if (bigInt.data[i] != 0) break;
    printf("%d", bigInt.data[i]);
    for (i--; i >= 0; i--) printf("%09d", bigInt.data[i]);
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        BigInt a = readBigInt();
        getchar();
        char op = getchar();
        BigInt b = readBigInt();
        BigInt result;
        switch (op) {
            case '+': result = add(a, b); break;
            case '-': result = subtract(a, b); break;
            case '*': result = multiply(a, b); break;
            case '/': result = divide(a, b); break;
        }
        writeBigInt(result);
    }
    return 0;
}
