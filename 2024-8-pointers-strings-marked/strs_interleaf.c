#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        char *s1 = calloc(1005, sizeof(char));
        char *s2 = calloc(1005, sizeof(char));
        int d1 = 0, d2 = 0, size = 0;
        char *pos1 = s1, *pos2 = s2;
        scanf(" %[^;];%[^;];%d;%d;%d", s1, s2, &d1, &d2, &size);
        char *s3 = calloc(2005, sizeof(char));
        int p = d1 + d2;
        for (int i = 0; i < size - 1; i++) {
            if (i % p < d1 && *pos1 != '\0' || *pos2 == '\0')
                *(s3 + i) = *pos1++;
            else if (i % p >= d1 && *pos2 != '\0' || *pos1 == '\0')
                *(s3 + i) = *pos2++;
        }
        printf("%s\n", s3);
        free(s1), free(s2), free(s3);
    }
}
