#include<stdio.h>

int main(void) {
    char s[20], m[20];
    int day, year, hour, minute, second;
    scanf("%s %d %d %s %d %d %d", s, &day, &year, m, &hour, &minute, &second);
    sscanf(s, "%3s", s);
    sscanf(m, "%3s", m);
    printf("%s %s %02d %02d:%02d:%02d %04d", m, s, day, hour, minute, second, year);
    return 0;
}