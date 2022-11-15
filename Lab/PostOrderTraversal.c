//INPUT
/*
No. of nodes: 6
Inorder traversal: 4, 2, 5, 1, 3, 6
Preorder traversal: 1, 2, 4, 5, 3, 6
*/

//OUTPUT
/*
Postorder traversal: 4, 5, 2, 6, 3, 1 
*/

//ALGORITHM/PSEUDOCODE
/*

*/

//CODE
/*
struct bst
{
    int data;
    struct bst *left, *right;
} *root;
void in_order(int i)
{
    {
        in_order(i / 2)
    }
}
void post_order(struct bst *ptr)
{
    if (ptr)
    {
        post_order(ptr->left);
        post_order(ptr->right);
        printf("%d ", *ptr);
    }
}
int main()
{

}
*/

#include <stdio.h>
int search(int *arr, int x, int n)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
void printPostOrder(int *in, int *pre, int n)
{
    int root = search(in, pre[0], n);
    if (root != 0)
        printPostOrder(in, pre + 1, root);
    if (root != n - 1)
        printPostOrder(in + root + 1, pre + root + 1, n - root - 1);
    printf("%d ", pre[0]);
}
int main()
{
    int i, n;
    scanf("%d", &n);
    int in[n], pre[n];
    for (i = 0; i < n; i++)
        scanf("%d", &in[i]);
    for (i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    printf("Postorder traversal: ");
    printPostOrder(in, pre, n);
    return 0;
}