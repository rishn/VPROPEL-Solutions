#include <stdio.h>
int stk[100], tq[100], front = 0, rear = -1, tfront = 0, trear = -1;
int is_empty()
{
    if (rear == -1)
    {
        printf("Empty stack (queue)\n");
        return 1;
    }
    return 0;
}
int is_full()
{
    if (rear == 99)
    {
        printf("Full stack (queue)\n");
        return 1;
    }
    return 0;
}
void push(int x, int m)
{
    if (m)
    {
        if (is_full() == 1)
            return;
        stk[++rear] = x;
    }
    else
        tq[++trear] = x;
}
int dequeue(int m)
{
    if (m)
    {
        if (is_empty() == 1)
            return -1;
        return stk[front++];
    }
    else
        return tq[tfront++];
}
int pop()
{
    int i, x, t, l = rear;
    for (i = front; i < l; i++)
    {
        t = dequeue(1);
        if (t == -1)
            return t;
        push(t, 0);
    }
    x = dequeue(1);
    l = trear;
    for (i = front; i <= l; i++)
        push(dequeue(0), 0);
    tfront = 0;
    trear = -1;
    return x;
}
void display()
{
    if (! is_empty())
        for (int i = front; i <= rear; i++)
            printf("%d\n", stk[i]);
}
int main()
{
    int x, reply = 0;
    while (reply != 4)
    {
        printf("1. Push\t2. Pop\t3. View\t4. Exit\n");
        scanf("%d", &reply);
        if (reply == 1)
        {
            printf("Enter element: ");
            scanf("%d", &x);
            push(x, 1);
        }
        else if (reply == 2)
        {
            x = pop();
            if (x != - 1)
                printf("Popped element: %d\n", x);
        }
        else if (reply == 3)
            display();
        else if (reply != 4)
            printf("Invalid request\n");
    }
}