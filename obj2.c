#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

// Push
void push(char item)
{
    stack[++top] = item;
}

// Pop
char pop()
{
    return stack[top--];
}

// Peek
char peek()
{
    return stack[top];
}

// Check precedence
int precedence(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char symbol;

    for (i = 0; infix[i] != '\0'; i++)
    {

        symbol = infix[i];

        // Operand
        if (isalnum(symbol))
        {
            postfix[j++] = symbol;
        }

        // Left parenthesis
        else if (symbol == '(')
        {
            push(symbol);
        }

        // Right parenthesis
        else if (symbol == ')')
        {

            while (peek() != '(')
            {
                postfix[j++] = pop();
            }

            pop();
        }

        // Operator
        else
        {

            while (top != -1 &&
                   precedence(symbol) <= precedence(peek()))
            {

                postfix[j++] = pop();
            }

            push(symbol);
        }
    }

    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main()
{

    char infix[100], postfix[100];

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}