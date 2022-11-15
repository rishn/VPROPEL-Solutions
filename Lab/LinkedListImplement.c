#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
} *head = NULL, *new_node, *last, *del_node, *prev, *temp;
void get_node()
{
    new_node = (struct node *)malloc(sizeof(struct node));
}
void read_node()
{
    scanf("%d", &new_node->data);
    new_node->link = NULL;
}
void create()
{
    int c;
    if (head != NULL)
    {
        printf("Linked list is already created\n");
        return;
    }
    else
    {
        do
        {
            get_node();
            read_node();
            if (head == NULL)
            {
                last = new_node;
                head = last;
            }
            else
            {
                last->link = new_node;
                last = last->link;
            }
            printf("Press 1 to add another node: ");
            scanf("%d", &c);
        } while (c == 1);
    }
    return;
}
void insert_last()
{
    get_node();
    if (new_node == NULL)
    {
        printf("Memory insufficient\n");
        return;
    }
    read_node();
    if (head == NULL)
    {
        last = new_node;
        head = last;
        return;
    }
    last->link = new_node;
    last = last->link;
}
int insert_first()
{
    get_node();
    if (new_node == NULL)
    {
        printf("No memory\n");
        return 0;
    }
    read_node();
    if (head == NULL)
    {
        last = new_node;
        head = last;
        return 0;
    }
    new_node->link = head;
    head = new_node;
}
void modify()
{
    int x;
    if (head == NULL)
    {
        printf("SLL is Empty\n");
        return;
    }
    scanf("%d", &x);
    temp = head;
    while (temp == NULL)
    {
        if (temp->data == x)
        {
            scanf("%d", &temp->data);
            return;
        }
        else
        {
            temp = temp->link;
        }
    }
}
void insert_middle()
{
    int x;
    get_node();
    if (new_node == NULL)
    {
        printf("No memory\n");
        return;
    }
    read_node();
    if (head == NULL)
    {
        last = new_node;
        head = last;
        return;
    }
    printf("Enter the node after which you want to insert new node: ");
    scanf("%d", &x);
    temp = head;
    while (temp != NULL)
    {
        if (temp != NULL)
        {
            new_node->link = temp->link;
            temp->link = new_node;
            return;
        }
        else
            temp = temp->link;
        return;
    }
}
void del_first()
{
    if (head == NULL)
    {
        printf("SLL is empty");
        return;
    }
    else if (head == last)
    {
        del_node = head;
        printf("Deleted node is %d\n", del_node->data);
        last = NULL;
        head = last;
        free(del_node);
        return;
    }
    else
    {
        del_node = head;
        printf("Deleted node is %d\n", del_node->data);
        head = head->link;
        free(del_node);
        return;
    }
}
void del_last()
{
    if (head == NULL)
    {
        printf("SLL is empty\n");
        return;
    }
    else if (head == last)
    {
        del_node = head;
        printf("Deleted node is %d\n", del_node->data);
        last = NULL;
        head = last;
        free(del_node);
        return;
    }
    else
    {
        last = head;
        while (last->link != NULL)
        {
            prev = last;
            last = last->link;
        }
        del_node = last;
        printf("Deleted node is %d\n", del_node->data);
        last = prev;
        last->link = NULL;
        free(del_node);
        return;
    }
}
void del_middle()
{
    int x;
    if (head == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    else if (head == last)
    {
        del_node = head;
        printf("Deleted node is %d\n", del_node->data);
        last = NULL;
        head = last;
        free(del_node);
        return;
    }
    else
    {
        temp = head;
        printf("Enter element to be deleted\n");
        scanf("%d", &x);
        while (temp != NULL)
        {
            if (temp->data == x)
            {
                del_node = temp;
                printf("Deleted node is %d\n", del_node->data);
                prev->link = temp->link;
                free(del_node);
                return;
            }
            else
            {
                prev = temp;
                temp = temp->link;
            }
        }
    }
}
void display()
{
    if (head == NULL)
    {
        printf("SLL is empty\n");
        return;
    }
    temp = head;
    while (temp == NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->link;
    }
}
int main()
{
    create();
    insert_last();
    insert_last();
    insert_last();
    insert_first();
    insert_middle();
    display();
    del_middle();
    del_first();
    del_last();
}