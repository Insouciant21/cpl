#include <stdio.h>

enum
{
    MAXN = 200002,
    INF = 0x3f3f3f3f
};

int a[MAXN], b[MAXN], c[MAXN * 2];

int main(void)
{
    int n_1, n_2, a_max = -INF, b_max = -INF;
    int* p = NULL, * q = NULL;
    scanf("%d", &n_1);
    for (int i = 0; i < n_1; i++) {
        scanf("%d", &a[i]);
        if (a[i] > a_max) { p = a + i, a_max = a[i]; }
    }
    scanf("%d", &n_2);
    for (int i = 0; i < n_2; i++)
    {
        scanf("%d", &b[i]);
        if (b[i] > b_max) { q = b + i, b_max = b[i]; }
    }
    int* ptr_a = a, * ptr_b = b, * ptr_c = c;
    int* end_a = a + n_1, * end_b = b + n_2;
    while (ptr_a <= p || ptr_b <= q)
    {
        if (ptr_a > p) *ptr_c++ = *ptr_b++;
        else if (ptr_b > q) *ptr_c++ = *ptr_a++;
        else if (*ptr_a < *ptr_b) *ptr_c++ = *ptr_a++;
        else *ptr_c++ = *ptr_b++;
    }
    while (ptr_a < end_a || ptr_b < end_b)
    {
        if (ptr_a >= end_a) *ptr_c++ = *ptr_b++;
        else if (ptr_b >= end_b) *ptr_c++ = *ptr_a++;
        else if (*ptr_a > *ptr_b) *ptr_c++ = *ptr_a++;
        else *ptr_c++ = *ptr_b++;
    }
    for (int i = 0; i < n_1 + n_2; i++) printf("%d ", c[i]);
}