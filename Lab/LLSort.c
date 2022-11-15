//INPUT
/*
5
2 3 4 1 5
4
*/

//OUTPUT
/*
1 2 3 4 
5 
*/

//CODE
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void swapnodes(struct node **head_ref, struct node *currX, struct node *currY, struct node *prevY)
{
    *head_ref = currY;
    prevY->link = currX;
    struct node* temp = currY->link;
    currY->link = currX->link;
    currX->link = temp;
}
struct node *selectionSort(struct node *head)
{
    if (head->link == NULL)
        return head;
    struct node *min = head;
    struct node *beforeMin = NULL;
    struct node *ptr;
    for (ptr = head; ptr->link != NULL; ptr = ptr->link)
    {
        if (ptr->link->data < min->data)
        {
            min = ptr->link;
            beforeMin = ptr;
        }
    }
    if (min != head)
        swapnodes(&head, head, min, beforeMin);
    head->link = selectionSort(head->link);
    return head;
}
void sort(struct node **head_ref)
{
    if ((*head_ref) == NULL)
        return;
    *head_ref = selectionSort(*head_ref);
}
void push(struct node** head_ref, int new_data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->link = (*head_ref);
    (*head_ref) = new_node;
}
void printList(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->link;
    }
}
int main()
{
    struct node *head = NULL, *p1_head = NULL, *p2_head = NULL, *temp;
    int i, n, d, k;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &d);
        push(&head, d);
    }
    sort(&head);
    temp = head;
    scanf("%d", &k);
    push(&p1_head, temp->data);
    do
    {
        temp = temp->link;
        push(&p1_head, temp->data);
    } while (temp->data != k);
    temp = temp->link;
    sort(&p1_head);
    printList(p1_head);
    printf("\n");
    while (temp != NULL)
    {
        push(&p2_head, temp->data);
        temp = temp->link;
    }
    sort(&p2_head);
    printList(p2_head);
    return 0;
}
