# include <stdio.h>
# define MAX_SZE 10

int A[MAX_SIZE];
int top=-1;

void push(int x)
{
    if (top == MAX_SIZE-1)
    {
        printf("Error:Stack Overflow\n");
        return;
    }
    A[++top]=x;
}

void pop()
{
    if (top==-1)
    {
        printf("Error: No element to pop\n");
        return;
    }
    top--;
}
int top()
{
    return A[top];
}