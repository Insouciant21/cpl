#include <stdio.h>

char *ones[] = {"zero",     "one",     "two",     "three",     "four",     "five",    "six",
                "seven",    "eight",   "nine",    "ten",       "eleven",   "twelve",  "thirteen",
                "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

char *tens[] = {"0", "1", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

void printTwo(int n) {
    if (n < 20) printf("%s", ones[n]);
    else if (n % 10 == 0) printf("%s", tens[n / 10]);
    else printf("%s-%s", tens[n / 10], ones[n % 10]);
}

int main() {
    int n;
    scanf("%d", &n);
    if (n >= 100) {
        int t = n % 100;
        if (t != 0) {
            printf("%s hundred and ", ones[n / 100]);
            printTwo(t);
        }
        else printf("%s hundred", ones[n / 100]);
    }
    else printTwo(n);
    return 0;
}
