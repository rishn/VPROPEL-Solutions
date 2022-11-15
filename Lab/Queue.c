//INPUT
/*
1
5
10
20
30
40
50
1
2
4
99
*/

//OUTPUT
/*
50
-1
10
20
30
40

*/

//ALGORITHM/PSEUDOCODE
/*
q <- int array of size 100
even <- int array of size 100
odd <- int array of size 100
j <- 0
k <- 0
Enqueue(int i, int n)
{
    if (i == n)
    {
        return
    }
    read q[i]
    i += 1
    Enqueue(i, n)
}
Dequeue(int n)
{
    if (q[0] % 2 == 1)
    {
        odd[j] <- q[0]
        j += 1
    }
    else
    {
        even[k] <- q[0]
        k += 1
    }
    i <- 0
    until (i >= n - 1)
    {
        q[i] <- q[i + 1]
        i += 1
    }
}
Display(int n, int m)
{
    i <- 0
    until (i >= n - m)
    {
        print q[i] + "\n"
        i += 1
    }
    if (j == 0)
    {
        print "-1\n"
    }
    else
    {
        i <- 0
        until (i >= j)
        {
            print odd[i] + "\n"
            i += 1
        }
    }
    if (k == 0)
    {
        print "-99\n"
    }
    else
    {
        i <- 0
        until (i >= k)
        {
            print even[i] + "\n"
            i += 1
        }
    }
}
m <- 0, i <- 0, t <- 0
read option
if (option == 1)
{
    read n
    Enqueue(i, n)
    t += n
    read option
    if (option == 1)
    {
        while (1)
        {
            if (option == 99)
            {
                break
            }
            read option
            if (option == 1)
            {
                read n
                i <- t
                Enqueue(i, t + n)
                t += n
            }
            else if (option == 2)
            {
                read m
                i <- 0
                until (i >= m)
                {
                    Dequeue(t)
                    i += 1
                }
            }
            else
            {
                Display(n, m)
            }
        }
    }
    else
    {
        end program execution
    }
} 
end program execution
*/

//PROCESS
/*
Used queue implementation functions such as enqueue, dequeue, display. 
Enqueue - recursive function to add n elements to queue by reading n.
Dequeue - Delete first element of queue and add it to even array or odd array depending on if it is even or odd.
Display - Display elements of queue, display -1 if even array is empty else print all elements of array, 
display -99 if odd array is empty else print all elements of array
In main program, after reading option, if option is 1, perform enqueue operation. 
After reading option, if option is 1, run a while loop where if option is 99, break. 
Read option - if option is 1, perform enqueue operation; else if option is 2, perform dequeue operation; else, perform display operation.                                                     
*/

//ALT SOLUTIONS
/*
Can use linked lists instead of arrays to store integers.
Can declare variables and return them via functions instead of declaring global variables.
*/

//CODE
#include <stdio.h>
#include <stdlib.h>
int q[100], even[100], odd[100];
int j = 0, k = 0;
void enqueue(int i, int n)
{
    if (i == n)
        return;
    scanf("%d", &q[i++]);
    enqueue(i, n);
}
void dequeue(int n)
{
    int i;
    if (q[0] % 2)
        odd[j++] = q[0];
    else
        even[k++] = q[0];
    for (i = 0; i < n - 1; i++)
        q[i] = q[i + 1];
}
void display(int n, int m)
{
    int i;
    for (i = 0; i < n - m; i++)
        printf("%d\n", q[i]);
    if (j == 0)
        printf("-1\n");
    else
        for (i = 0; i < j; i++)
            printf("%d\n", odd[i]);
    if (k == 0)
        printf("-99\n");
    else
        for (i = 0; i < k; i++)
            printf("%d\n", even[i]);
}
int main()
{
    int option, n, m = 0, i = 0, t = 0;
    scanf("%d", &option);
    if (option == 1)
    {
        scanf("%d", &n);
        enqueue(i, n);
        t += n;
        scanf("%d", &option);
        if (option == 1)
        {
            while (1)
            {
                if (option == 99)
                    break;
                scanf("%d", &option);
                if (option == 1)
                {
                    scanf("%d", &n);
                    i = t;
                    enqueue(i, t + n);
                    t += n;
                }
                else if (option == 2)
                {   
                    scanf("%d", &m);
                    for (i = 0; i < m; i++)
                        dequeue(t);
                }
                else
                    display(n, m);
            }
        }
        else
            return 0;
    }
    return 0;
}