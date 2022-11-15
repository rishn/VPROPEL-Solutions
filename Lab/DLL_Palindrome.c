//INPUT
/*
5
1
2
3
121
5
*/

//OUTPUT
/*
1
2
3
5

*/

//ALGORITHM/PSEUDOCODE
/*
define struct node
{
    declare int data
    declare node pointer flink, blink
} pointers as head, new_node, temp, pointer, next
Palindrome()
{
    pointer <- head
    until (pointer == NULL)
    {
        if (pointer->data > 9)
        {
            t <- pointer->data
            l <- 0
            until (t <= 0)
            {
                t /= 10
                l += 1
            }
            i <- 0
            p <- 1
            until (i >= l / 2 + l % 2)
            {
                p *= 10
                i += 1
            }
            n1 <- pointer->data / p
            t <- pointer->data
            n2 <- 0
            i <- 0
            p <- 1
            until (i >= l % 2 - 1)
            {
                p *= 10
                i += 1
            }
            until (p <= 0)
            {
                n2 += (t % 10) * p
                t /= 10
                p /= 10
            }
            if (n1 == n2)
            {
                pointer->flink->blink <- pointer->blink
                pointer->blink->flink <- pointer->flink
            }
        }
        pointer <- pointer->flink
    }
    next <- head
    until (next == NULL)
    {
        print next->data + "\n"
        next <- next->flink
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
            head->blink <- NULL
            temp <- head
        }
        else
        {
            temp->flink <- new_node
            new_node->blink <- temp
            temp <- temp->flink
        }
        n -= 1
    }
    temp->flink <- NULL
}
DLL_Palindrome()
{
    head <- NULL
    read n
    Create(n)
    Palindrome()
}
*/

//PROCESS
/*
Using doubly linked linked lists to process given inputs.
Create() creates the linked list by allocating memory for each element and reading the data of the node. 
The new node is assigned to the flink of the traversing pointer and the pointer is assigned to the blink of the new node.
and at every iteration, the flink of the pointer is assigned to the pointer. The loop runs n times (n = no. of elements).
Once out of the loop, NULL is assigned to the link of the last node.
In Palindrome(), node pointer is used to traverse entire linked list where the data of pointer is split into two halves.
The second half is reversed and compared with the first half.
If the halves match, the node is diconnected from its blink node and flink node (thereby node is removed from list).
Once out of the traversal loop, another pointer traverses through the entire list and prints the corresponding data.
*/

//ALT SOLUTIONS
/*
Can use singly, circular singly or circular doubly linked lists to perform the following operation. 
Static arrays can also be used if required.
*/

//CODE
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *flink, *blink;
} *head = NULL, *new_node, *temp, *pointer, *next;
void palindrome()
{
    int i, x, l, t, p, q, n1, n2;
    for (pointer = head; pointer != NULL; pointer = pointer->flink)
    {
        if (pointer->data > 9)
        {
            t = pointer->data;
            for (l = 0; t > 0; l++)
                t /= 10;
            for (i = 0, p = 1; i < l / 2 + l % 2; i++)
                    p *= 10;
            n1 = pointer->data / p;
            t = pointer->data;
            n2 = 0;
            for (i = 0, p = 1; i < l % 2 - 1; i++)
                p *= 10;
            for (; p > 0; p /= 10)
            {
                n2 += (t % 10) * p;
                t /= 10;
            }
            if (n1 == n2)
            {
                pointer->flink->blink = pointer->blink;
                pointer->blink->flink = pointer->flink;
            }
        }
    }
    for (next = head; next != NULL; next = next->flink)
        printf("%d\n", next->data);
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
            head->blink = NULL;
            temp = head;
        }
        else
        {
            temp->flink = new_node;
            new_node->blink = temp;
            temp = temp->flink;
        }
    }
    temp->flink = NULL;
}
int main()
{
    int n;
    scanf("%d", &n);
    create(n);
    palindrome();
}