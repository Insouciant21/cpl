#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int a[114514], n;
        scanf("%d", &n);
        memset(a, 0, sizeof a);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int flag = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[n - 1])
            {
                flag = 0;
                break;
            }
        }
        if (flag) puts("Yes");
        else puts("No");
    }
}
