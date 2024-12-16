#include <stdio.h>

static char *ones[] = {"zero", "one", "two", "three", "four", "five", "six",
                       "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen",
                       "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

static char *tens[] = {"0", "1", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

void printTwo(long long n) {
    if (n < 20) printf("%s", ones[n]);
    else if (n % 10 == 0) printf("%s", tens[n / 10]);
    else printf("%s-%s", tens[n / 10], ones[n % 10]);
}

void printHundred(long long n) {
    if (n >= 100) {
        if (n % 100 != 0) {
            printf("%s hundred and ", ones[n / 100]);
            printTwo(n % 100);
        }
        else printf("%s hundred", ones[n / 100]);
    }
    else printTwo(n);
}

void print_number(long long n) {
    if (n >= 1000000000) {
        printHundred(n / 1000000000);
        printf(" billion ");
        n %= 1000000000;
    }
    if (n >= 1000000) {
        printHundred(n / 1000000);
        printf(" million ");
        n %= 1000000;
    }
    if (n >= 1000) {
        printHundred(n / 1000);
        printf(" thousand ");
        n %= 1000;
    }
    if (n != 0) printHundred(n);
}

int main() {
    long long n;
    scanf("%lld", &n);
    if (n < 0) {
        printf("minus ");
        n = -n;
    }
    if (n == 0) puts("zero");
    else print_number(n);
}