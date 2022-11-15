//INPUT
/*
5
1
2
3
4
5
*/

//OUTPUT
/*
1
3
5

*/

//ALGORITHM/PSEUDOCODE
/*
define struct node
{
    declare int data
    declare node pointer link
} pointers as head, new_node, temp, pointer
SLL_Odd()
{
    pointer <- head
    c <- 0
    until (pointer == NULL)
    {
        if (pointer->data % 2 == 1)
        {
            print pointer->data + "\n"
            c += 1
        }
        pointer <- pointer->link
    }
    if (c == 0)
    {
        print -1
    }
}
Create(int n)
{
    until (n <= 0)
    {
        new_node <- new node pointer of size of struct node
        read new_node->data
        if (head == NULL)
        {
            head <- new_node
            temp <- head
        }
        else
        {
            temp->link <- new_node
            temp <- temp->link
        }
        n -= 1
    }
    temp->link <- NULL
}
SLL_Odd_Main()
{
    head <- NULL
    read n
    Create(n)
    SLL_Odd()
}
*/

//PROCESS
/*
Using singly linked linked lists to process given inputs.
Create() creates the linked list by allocating memory for each element and reading the data of the node. 
The new node is assigned to the link of the traversing pointer 
and at every iteration, the link of the pointer is assigned to the pointer. The loop runs n times (n = no. of elements).
Once out of the loop, NULL is assigned to the link of the last node.
In F1(), while loop is run where the pointers traverse through the entire linked list 
and the pointer checks if its data is odd and prints it.
*/

//ALT SOLUTIONS
/*
Can use circular singly, doubly or circular doubly linked lists to perform the following operation. 
Static arrays can also be used if required.
*/

//CODE
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
} *head = NULL, *new_node, *temp, *pointer;
void sll_odd()
{
    int c = 0;
    for (pointer = head; pointer != NULL; pointer = pointer->link)
        if (pointer->data % 2)
        {
            printf("%d\n", pointer->data);
            c++;
        }
    if (! c)
        printf("-1");
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
    sll_odd();
}