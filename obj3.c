#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

// Push
void push(int value)
{
    stack[++top] = value;
}

// Pop
int pop()
{
    return stack[top--];
}

// Evaluate prefix
int evaluatePrefix(char prefix[])
{

    int i, op1, op2;

    for (i = strlen(prefix) - 1; i >= 0; i--)
    {

        char symbol = prefix[i];

        // Ignore spaces
        if (symbol == ' ')
            continue;

        // Operand
        if (isdigit(symbol))
        {
            push(symbol - '0');
        }

        // Operator
        else
        {

            op1 = pop();
            op2 = pop();

            switch (symbol)
            {

            case '+':
                push(op1 + op2);
                break;

            case '-':
                push(op1 - op2);
                break;

            case '*':
                push(op1 * op2);
                break;

            case '/':
                push(op1 / op2);
                break;
            }
        }
    }

    return pop();
}

int main()
{

    char prefix[100];

    printf("Enter Prefix Expression: ");
    gets(prefix);

    printf("Result = %d\n", evaluatePrefix(prefix));

    return 0;
}