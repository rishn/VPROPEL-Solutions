//INPUT
/*
23+
*/

//OUTPUT
/*
5
*/

//PSEUDOCODE/ALGORITHM
/*
Is_Empty()
{
    if (top == -1)
    {
        return 1
    }
    return 0
}
Is_Full()
{
    if (top == l - 1)
    {
        return 1
    }
    return 0
}
Push(int x)
{
    if (Is_Full() == 1)
    {
        print "Stack is Full\n"
    }
    else
    {
        top += 1
        stack[top] = x
    }
}
Pop()
{
    if (Is_Empty() == 1)
    {
        print "Stack is empty\n"
        return 0
    }
    return stack[top]
    top -= 1
}
Display()
{
    if (Is_Empty() == 1)
    {
        print "Stack is empty\n"
    }
    else
    {
        print stack[top]
    }
}
Postfix_Eval()
{
    read char array pfx
    top <- -1
    l <- length(pfx)
    stack <- int array of size l
    i <- 0
    until (i >= l)
    {
        if (pfx[i] >= '0' && pfx[i] <= '9)
        {
            Push((int)pfx[i] - (int)'0')
        }
        else
        {
            y <- Pop()
            x <- Pop()
            if (pfx[i] == '+')
            {
                Push(x + y)
            }
            else if (pfx[i] == '*')
            {
                Push(x * y)
            }
            else if (pfx[i] == '-')
            {
                Push(x - y)
            }
            else if (pfx[i] == '/')
            {
                Push(x / y)
            }
            else
            {
                r <- x
                while (y > 1)
                {
                    r *= x
                    y -= 1
                }
                Push(r)
            }
        }
        i += 1
    }
    Display()
}
*/

//PROCESS
/*
Using stacks to evaluate postfix expression and print result.
Every element (char) of postfix expression is checked under a for loop where:
If element is an integer, it is pushed to stack.
Else if element is an operation, 2 integers at the top of stack are popped and the operation is performed on the integers, whose result is pushed back into the stack.
Once out of the for loop, the final result, which is located at the index given by value assigned to top of the stack is printed.
*/

//ALT SOLUTIONS
/*
Can use other data structures such as queues, linked lists etc... to evaluate a postfix expression. 
Can use while loop instead of for loop used.
*/

//CODE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int *stack, top, l;
int is_empty()
{
    if (top == -1)
        return 1;
    return 0;
}
int is_full()
{
    if (top == l - 1)
        return 1;
    return 0;
}
void push(int x)
{
    if (is_full())
        printf("Stack is full\n");
    else
        stack[++top] = x;
}
int pop()
{
    if (is_empty())
        return 0;
    return stack[top--];
}
void display()
{
    if (is_empty())
        printf("Stack is empty\n");
    else
        printf("%d", stack[top]);
}
int main()
{
    char pfx[50];
    scanf("%s", &pfx);
    l = strlen(pfx);
    stack = (int *)malloc(sizeof(int) * l);
    top = -1;
    for (int i = 0; i < l; i++)
    {
        if (pfx[i] >= '0' && pfx[i] <= '9')
            push(pfx[i] - '0');
        else
        {
            int y = pop(), x = pop();
            if (pfx[i] == '+')
                push(x + y);
            else if (pfx[i] == '*')
                push(x * y);
            else if (pfx[i] == '-')
                push(x - y);
            else if (pfx[i] == '/')
                push(x / y);
            else
            {
                int r = x;
                while (y > 1)
                {
                    r *= x;
                    y--;
                }
                push(r);
            }
        }
    }
    display();
    return 0;
}