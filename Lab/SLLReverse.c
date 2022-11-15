#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
} *head = NULL, *new_node, *t, *temp, *next, *prev;
void reverse()
{
    next = head;
    prev = NULL;
    new_node = NULL;
    while (next != NULL)
    {
        new_node = next;
        next = next->link;
        new_node->link = prev;
        prev = new_node;
        head = new_node;
    }
}
void display()
{
    for (t = head; t != NULL; t = t->link)
        printf("%d ", t->data);
}
void create(int n)
{
    for (; n; n--)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &new_node->data);
        if (head == NULL)
        {
            head = new_node;
            temp = head;
        }
        else
        {
            temp->link = new_node;
            temp = temp->link;
        }
    }
    temp->link = NULL;
}
int main()
{
    int n;
    scanf("%d", &n);
    create(n);
    reverse();
    display();
}