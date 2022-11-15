//INPUT
/*
{(a+b)-[c/d]*e} 
*/

//OUTPUT
/*
Balanced
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
Push(char x)
{
    if (Is_Full() == 1)
    {
        print "Stack is full\n"
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
        return 0
    }
    x <- stack[top]
    top -= 1
    return x
}
Balance_Parantheses()
{
    read char array infx
    top <- -1
    l <- length(infx)
    stack <- char array of size l
    i <- 0
    until (i >= l)
    {
        if (infx[i] == '(' || infx[i] == '[' || infx[i] == '{')
        {    
            Push(infx[i])
        }
        else if (infx[i] == ')')
        {
            if (Pop() != '(')
            {
                 print "Unbalanced"
                 return
            }
        }
        else if (infx[i] == ']')
        {
            if (Pop() != '[')
            {
                 print "Unbalanced"
                 return
            }
        }
        else if (infx[i] == '}')
        {
            if (Pop() != '{')
            {
                 print "Unbalanced"
                 return
            }
        }
        i += 1
    }
    if (Is_Empty() == 1)
    {
        print "Balanced"
    }
}
*/

//PROCESS
/*
Using stacks to evaluate if parentheses are balanced in given expression.
Every element (char) of infix expression is checked under a for loop where:
If element is a left bracket, the element is pushed to stack.
Else if element is a right bracket, if the element popped from the stack is not the corresponding left bracket, expression has unbalanced brackets.
Once out of the for loop, if stack is empty, the expression has balanced brackets.
*/

//ALT SOLUTIONS
/*
Can use other data structures such as queues, linked lists, etc... to evaluate whether a given expression has balanced brackets or not. 
Can also use while loop instead of for loop used.
*/

//CODE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *stack;
int top, l;
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
void push(char x)
{
    if (is_full())
        printf("Stack is full\n");
    else
        stack[++top] = x;
}
char pop()
{
    if (is_empty())
        return 0;
    return stack[top--];
}
int main()
{
    char infx[50];
    scanf("%s", &infx);
    top = -1;
    l = strlen(infx);
    stack = (char *)malloc(sizeof(char) * l);
    for (int i = 0; i < l; i++)
    {
        if (infx[i] == '(' || infx[i] == '[' || infx[i] =='{')
            push(infx[i]);
        else if (infx[i] == ')')
        {
            if (pop() != '(')
            {
                printf("Unbalanced");
                return 0;
            }
        }
        else if (infx[i] ==']')
        {
            if (pop() != '[')
            {
                printf("Unbalanced");
                return 0;
            }
        }
        else if (infx[i] == '}')
        {
            if (pop() != '{')
            {
                printf("Unbalanced");
                return 0;
            }
        }
    }
    if (is_empty())
        printf("Balanced");
    return 0;
}