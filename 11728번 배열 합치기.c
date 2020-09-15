#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int m, n;
    int tmp = 0, tmp2 = 0;
    scanf("%d %d", &n, &m);
    int* narr = (int*)malloc(sizeof(int) * n);
    int* marr = (int*)malloc(sizeof(int) * m);


    for (int i = 0; i < n; i++)
    {
        scanf("%d", &narr[i]);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &marr[i]);
    }

    while (tmp < n && tmp2 < m)
    {
        if (narr[tmp] <= marr[tmp2])
            printf("%d ", narr[tmp++]);
        else
            printf("%d ", marr[tmp2++]);
    }

    if (tmp == n)
        for (int i = tmp2; i < m; i++)
        {
            printf("%d ", marr[i]);;
        }
    else
        for (int i = tmp; i < n; i++)
        {
            printf("%d ", narr[i]);
        }


    return 0;
}