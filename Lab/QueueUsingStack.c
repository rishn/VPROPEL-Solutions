#include <stdio.h>
int q[100], ts[100], top, ttop, l;
int is_empty()
{
    if (top == -1)
    {
        printf("Empty queue (stack)\n");
        return 1;
    }
    return 0;
}
int is_full()
{
    if (top == 99)
    {
        printf("Full queue (stack)\n");
        return 1;
    }
    return 0;
}
void enqueue(int x, int m)
{
    if (m == 1)
    {
        if (is_full())
            return;
        q[++top] = x;
    }
    else
        ts[++ttop] = x;
}
int pop(int m)
{
    if (m == 1)
    {
        if (is_empty())
            return -1;
        return q[top--];
    }
    else
        return ts[ttop--];
}
int dequeue()
{
    int i, x, t, l = top;
    for (i = 0; i < l; i++)
    {
        t = pop(1);
        if (t == -1)
            return t;
        enqueue(t, 0);
    }
    x = pop(1);
    for (i = 0; i < l; i++)
        enqueue(pop(0), 1);
    return x;
}
void display()
{
    if (! is_empty())
        for (int i = 0; i <= top; i++)
            printf("%d\n", q[i]);
}
int main()
{
    top = -1;
    ttop = -1;
    int reply;
    do
    {
        printf("1. Enqueue\t2. Dequeue\t3. View\t4. Exit\t");
        scanf("%d", &reply);
        if (reply == 1)
        {
            int x;
            printf("Enter element: ");
            scanf("%d", &x);
            enqueue(x, 1);
        }
        else if (reply == 2)
        {
            int x = dequeue();
            if (x != -1)
                printf("Dequeued element: %d\n", x);
        }
        else if (reply == 3)
            display();
        else if (reply != 4)
            printf("Invalid request\n");
    } while (reply != 4);
    return 0;
}