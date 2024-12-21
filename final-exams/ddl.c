#include <stdio.h>
#include <stdlib.h>

typedef struct Task
{
    int t;
    int ddl;
} Task;

Task p[150];

int cmp(const void* a, const void* b)
{
    return -((Task*)a)->ddl + ((Task*)b)->ddl;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d%d", &p[i].t, &p[i].ddl);
    qsort(p, n, sizeof(Task), cmp);
    int lastTime = p[0].ddl;
    for (int i = 0; i < n; i++)
    {
        int must_time;
        if (p[i].ddl > lastTime) must_time = lastTime - p[i].t;
        else must_time = p[i].ddl - p[i].t;
        if (must_time < 0)
        {
            printf("-1\n");
            return 0;
        }
        lastTime = must_time;
    }
    printf("%d\n", lastTime);
}