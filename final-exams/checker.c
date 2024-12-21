#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int len;
        scanf("%d", &len);
        char a[114514], b[114514];
        scanf("%s%s", a, b);
        size_t len_b = strlen(b);
        char* end1 = a + len - 1, * end2 = b + len_b - 1;
        for (int i = 0; i < len; i++)
            if (a[i] == '?' && a[len - i - 1] != '?') a[i] = a[len - i - 1];
        if (strcmp(a, b) == 0) { puts("Correct."); continue; }
        int flags = 0;
        for (int i = 0; i < len; i++)
        {
            if (a[i] == '?')
            {
                flags = 1;
                break;
            }
        }
        for (size_t i = 0; i < len_b; i++) if (b[i] == '?') { flags = 1; break; }
        if (!flags) { puts("Wrong Answer!"); continue; }
        char* p = b;
        flags = 0;
        for (int i = 0; i < len; i++)
        {
            if (a[i] == '?') { p += 2; continue; }
            if (a[i] != *p) { puts("Wrong Answer!"); flags = 1; break; }
            *p = 0;
            p++;
        }
        if (flags) continue;
        for (size_t i = 0; i < len_b; i++)
        {
            if (b[i] != b[len_b - i - 1]) { puts("Wrong Answer!"); flags = 1; break; }
        }
        if (flags) continue;
        int used[100] = { 0 };
        for (size_t i = 0; i < len_b / 2; i++)
        {
            if (b[i] != 0)
            {
                int x = (b[i] - '0') * 10 + b[i + 1] - '0';
                int y = (b[i + 1] - '0') * 10 + b[i] - '0';
                if (used[x] && used[y]) { puts("Wrong Answer!"); flags = 1; break; }
                if (used[x]) used[y] = 1;
                else used[x] = 1;
                b[i] = b[i + 1] = b[len_b - i - 1] = b[len_b - i - 2] = 0;
                i++;
            }
        }
        if (flags) continue;
        puts("Correct.");
    }
}
