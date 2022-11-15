//INPUT
/*
(a+b)-c*d/e
*/

//OUTPUT
/*
ab+cd*e/-
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
Precedence(char x)
{
	if (x == '^')
	{
		return 3
	}
	else if (x == '*' || x == '/')
	{
		return 2
	}
	else if (x == '+' || x == '-')
	{
		return 1
	}
	else
	{
		return 0
	}
}
Postfix_To_Infix()
{
	i <- 0
	j <- 0
	read char array infx
	l <- length(infx)
	stack <- char array of size l
	pfx <- char array of size 50
	until (i >= l)
	{
		if (infx[i] == '(')
		{
			Push(infx[i])
		}
		else if (infx[i] >= 'a' && infx[i] <= 'z')
		{
			pfx[j] <- infx[i]
			j += 1
		}
		else if (infx[i] == '^' || infx[i] == '*' || infx[i] == '/' || infx[i] == '+' || infx[i] == '-')        
		{
			x <- Pop()
			until ((x != '^' && x != '*' && x != '/' && x != '+' && x != '-') || precedence(x) < precedence(infx[i]))
			{
				pfx[j] <- x
				j += 1
				x <- Pop()
			}
			Push(x)
			Push(infx[i])           
		}
		else if (infx[i] == ')')        
		{
			x <- Pop()
			until (x == '(')
			{
				pfx[j] <- x
				j += 1
				x <- Pop()
			}
		}
		i += 1
	}
	until (Is_Empty() == 1)
	{
		pfx[j] <- Pop()
		j += 1
	}
	print pfx
}
*/

//PROCESS
/*
Using stacks to convert infix to postfix expression.
Every element (char) of infix expression is checked under for loop where:
	If element is left paranthesis, push it to stack.
	Else if element is an operand, add it to postfix expression.
	Else if element is an operator:
		Pop element from stack and assign to variable x
		A while loop is run until x is not an operator or precedence(x) < precedence(element) where:
			x is added to postfix expression
			Element is popped from stack and assigned to x
		x is pushed to stack
		element is pushed to stack
	Else if element is right paranthesis:
		Pop element from stack and assign to x
		A while loop is run until x is a left paranthesis where:
			x is added to postfix expression
			Element is popped from stack and assigned to x
Until stack is empty
	Element is popped from stack and added to postfix expression
*/

//ALT SOLUTIONS
/*
Can use other data structures such as queues, linked lists, etc... to convert infix to postfix expression.
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
int precedence(char x)
{
	if (x == '^')
		return 3;
	else if (x == '*' || x == '/')
		return 2;
	else if (x == '+' || x == '-')
		return 1;
	else
		return 0;
}
int main()
{
	int i = 0, j = 0;
	char infx[50], pfx[50], x;
	scanf("%s", &infx);
	l = strlen(infx);
	top = -1;
	stack = (char *)malloc(sizeof(char) * l);
	for (i = 0; i < l; i++)
	{
		if (infx[i] == '(')
			push(infx[i]);
		else if (infx[i] >= 'a' && infx[i] <= 'z')
			pfx[j++] = infx[i];
		else if (infx[i] == '^' || infx[i] == '*' || infx[i] == '/' || infx[i] == '+' || infx[i] == '-')        
		{
			x = pop();
			while ((x == '^' || x == '*' || x == '/' || x == '+' || x == '-') && precedence(x) >= precedence(infx[i]))
			{
				pfx[j++] = x;
				x = pop();
			}
			push(x);
			push(infx[i]);           
		}
		else if (infx[i] == ')')        
		{
			x = pop();
			while (x != '(')
			{
				pfx[j++] = x;
				x = pop();
			}
		}
	}
	while (! is_empty())
		pfx[j++] = pop();
	printf("%s", pfx);
	return 0;
}