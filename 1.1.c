#include <stdio.h>
#define SIZE 20

int stack[SIZE];
int top = -1;

// Push operation
void push(int value)
{
    if (top < SIZE - 1)
    {
        top++;
        stack[top] = value;
        printf("%d pushed into stack\n", value);
    }
    else
    {
        printf("Stack is Full\n");
    }
}

// Pop operation
void pop()
{
    if (top >= 0)
    {
        printf("Popped: %d\n", stack[top]);
        top--;
    }
    else
    {
        printf("Stack is Empty\n");
    }
}

// Peek operation
void peek()
{
    if (top >= 0)
    {
        printf("Top element: %d\n", stack[top]);
    }
    else
    {
        printf("Stack is Empty\n");
    }
}

// Check if stack is full
void isFull()
{
    if (top == SIZE - 1)
        printf("Stack is Full\n");
    else
        printf("Stack is Not Full\n");
}

// Check if stack is empty
void isEmpty()
{
    if (top == -1)
        printf("Stack is Empty\n");
    else
        printf("Stack is Not Empty\n");
}

// Count elements
void count()
{
    printf("Total elements: %d\n", top + 1);
}

// Clear stack
void clear()
{
    top = -1;
    printf("Stack Cleared\n");
}

// Display stack
void display()
{
    if (top >= 0)
    {
        printf("Stack: ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Stack is Empty\n");
    }
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();

    peek();

    pop();

    display();

    count();

    isFull();

    isEmpty();

    clear();

    display();

    return 0;
}