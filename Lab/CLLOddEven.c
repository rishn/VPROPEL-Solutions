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
2
4

*/

//ALGORITHM/PSEUDOCODE
/*
define struct node
{
    declare int data
    declare node pointer link
} pointers as head, new_node, temp, t1, t2
F1()
{
    t1 <- head
    do
    {
        if (t1->data % 2)
        {
            print t1->data + "\n"
        }
        t1 <- t1->link
    } until (t1 == head)
    t2 <- head
    do
    {
        if (! (t2->data % 2))
        {
            print t2->data + "\n";
        }
        t2 <- t2->link
    } until (t2 == head)
}
Create(int n)
{
    until (n <= 0)
    {
        new_node <- new node pointer of size of struct node
        read new_node->data
        if (head == NULL)
        {
            head <- new_node;
            temp <- head;
        }
        else
        {
            temp->link <- new_node;
            temp <- temp->link;
        }
        n -= 1
    }
    temp->link <- head
}
CLL_Odd_Even()
{
    head <- NULL
    read n
    Create(n)
    F1()
}
*/

//PROCESS
/*
Using circular singly linked linked lists to process given inputs.
Create() creates the circular linked list by allocating memory for each element and reading the data of the node. 
The new node is assigned to the link of the traversing pointer and at every iteration, 
the link of the pointer is assigned to the pointer. The loop runs n times (n = no. of elements).
Once out of the loop, head is assigned to the link of the last node to make the linked list circular.
In F1(), 2 while loops are run where the pointers traverse through the entire linked list:
    In the first loop, the pointer checks if its data is odd and prints it. 
    In the second loop, the pointer checks if its data is even and prints it. 
*/

//ALT SOLUTIONS
/*
Can use singly or doubly or circular doubly linked lists to perform the following operation. 
Static arrays can also be used if required.
*/

//CODE
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
} *head = NULL, *new_node, *temp, *t1, *t2;
void f1()
{
    t1 = head;
    do {
        if (t1->data % 2)
            printf("%d\n", t1->data);
        t1 = t1->link;
    } while(t1 != head);
    t2 = head;
    do {
        if (! (t2->data % 2))
            printf("%d\n", t2->data);
        t2 = t2->link;
    } while (t2 != head);
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
    temp->link = head;
}
int main()
{
    int n;
    scanf("%d", &n);
    create(n);
    f1();
}