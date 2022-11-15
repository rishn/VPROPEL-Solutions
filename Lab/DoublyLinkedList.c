#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *flink;
    struct node *blink;

} *head = NULL, *new_node, *last, *del_node, *prev, *next, *temp;
void get_node()
{
    new_node = (struct node *)malloc(sizeof(struct node));
}
void read_node()
{
    scanf("%d", &new_node->data);
    new_node->flink = NULL;
    new_node->blink = NULL;
}
void create()
{
    int c;
    if (head != NULL)
    {
        printf("LL is already created\n");
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
                last->flink = new_node;
                new_node->blink = last;
                last = last->flink;
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
    last->flink = new_node;
    new_node->blink = last;
    last = last->flink;
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
    new_node->flink = head;
    head->blink = new_node;
    head = new_node;
}
void insert_middle()
{
    int x;
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
        return;
    }
    printf("Enter the node after which you want to insert new node: ");
    scanf("%d", &x);
    temp = head;
    while (temp != NULL)
        if (temp->data == x)
        {
            next = temp->flink;
            new_node->flink = next;
            temp->flink = new_node;
            new_node->blink = temp;
            return;
        }
        else
            temp = temp->link;
        return;
}
void del_first()
{
    if (head == NULL)
    {
        printf("DLL is empty");
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
        head = head-flink;
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
        del_node = last;
        printf("Deleted node is %d\n", del_node->data);
        last = last->blink;
        last->flink = NULL;
        free(del_node);
        return;
    }
}
void del_middle()
{
    int x;
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
        temp = head;
        printf("Enter element to be deleted\n");
        scanf("%d", &x);
        while (temp != NULL)
        {
            if (temp->data == x)
            {
                del_node = temp;
                printf("Deleted node is %d\n", del_node->data);
                next = temp->flink;
                prev = temp->blink;
                prev->flink = next;
                next->blink = prev;
                printf("Node deleted is %d\n", del_node->data);
                free(del_node);
                return;
            }
            else
            {
                temp = temp->flink;
            }
        }
    }
}
void display()
{
    if (head == NULL)
    {
        printf("DLL is empty\n");
        return;
    }
    temp = head;
    until (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->flink;
    }
}
void backward_display()
{
    if (head == NULL)
    {
        printf("DLL is empty\n");
        return;
    }
    temp = last;
    until (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->blink;
    }
}
