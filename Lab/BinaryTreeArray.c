#include <stdio.h>
void pre_order(int *a, int i, int n)
{
    if (i >= 1 && i <= n)
    {   
        printf("%d ", a[i]);
        pre_order(a, i * 2, n);
        pre_order(a, i * 2 + 1, n);
    }
}
void in_order(int *a, int i, int n)
{
    if (i >= 1 && i <= n)
    {    
        in_order(a, i * 2, n);
        printf("%d ", a[i]);
        in_order(a, i * 2 + 1, n);
    }
}
void post_order(int *a, int i, int n)
{
    if (i >= 1 && i <= n)
    {    
        post_order(a, i * 2, n);
        post_order(a, i * 2 + 1, n);
        printf("%d ", a[i]);
    }
}
int main()
{
    int i, n;
    scanf("%d", &n);
    int a[n + 1];
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    pre_order(a, 1, n);
    printf("\n");
    in_order(a, 1, n);
    printf("\n");
    post_order(a, 1, n);
}