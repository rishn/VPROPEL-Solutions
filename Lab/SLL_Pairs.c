//INPUT
/*
5
1
2
3
4
5
7
*/

//OUTPUT
/*
2
5
3
4

*/

//ALGORITHM/PSEUDOCODE
/*
define struct node
{
    declare int data
    declare node pointer link
} pointers as head, new_node, temp, t1, t2
SLL_Pre(int k)
{
    c <- 0
    t1 <- head
    until (t1 == NULL)
    {
        t2 = t1->link
        until (t2 == NULL)
        {
            if (t1->data + t2->data == k)
            {
                print t1->data + "\n" + t2->data + "\n;
                c += 1
            }
            t2 <- t2->link
        }
        t1 <- t1->link
    }
    if (c == 0)
        print "-1"
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
SLL_Pairs()
{
    head <- NULL
    read n
    Create(n)
    read k
    SLL_Pre(k)
}
*/

//PROCESS
/*
Using singly linked linked lists to process given inputs.
Create() creates the linked list by allocating memory for each element and reading the data of the node. 
The new node is assigned to the link of the traversing pointer 
and at every iteration, the link of the pointer is assigned to the pointer. The loop runs n times (n = no. of elements).
Once out of the loop, NULL is assigned to the link of the last node.
In Sll_Pre(), a nested for loop is run where node pointers t1 and t2 are used to traverse the entire linked list 
forming distinct pairs of elements and the nested if checks if the data of both pointers sums up to given integer k.
If condition is satisfied, data is printed and counter c is incremented (initialized to 0).
Once out of the for loop, if c is 0, -1 is printed.
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
} *head = NULL, *new_node, *temp, *t1, *t2;
void sll_pre(int k)
{
    int c = 0;
    for (t1 = head; t1 != NULL; t1 = t1->link)
        for (t2 = t1->link; t2 != NULL; t2 = t2->link)
            if (t1->data + t2->data == k)
            {
                printf("%d\n%d\n", t1->data, t2->data);
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
    int n, k;
    scanf("%d", &n);
    create(n);
    scanf("%d", &k);
    sll_pre(k);
}