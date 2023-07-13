#include <stdio.h>
#include <string.h>
#include <ctype.h>
void main()
{
    char infix[20], postfix[20];
    printf("enter the infix expression\n");
    scanf("%s", infix);
    intpo(infix, postfix);
    printf("postfix expression is:%s\n", postfix);
}
int input(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 3;
    case '^':
    case '$':
        return 6;
    case '(':
        return 9;
    case ')':
        return 0;
    default:
        return 7;
    }
}
int stack(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 4;
    case '^':
    case '$':
        return 5;
    case '(':
        return 0;
    case '#':
        return -1;
    default:
        return 8;
    }
}
void intpo(char infix[], char postfix[])
{
    int top = -1, i, j = 0;
    char s[30], symbol;
    s[++top] = '#';
    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        while (stack(s[top]) > input(symbol))
        {
            postfix[j++] = s[top--];
        }
        if (stack(s[top]) != input(symbol))
            s[++top] = symbol;
        else
            top--;
    }
    while (s[top] != '#')
    {
        postfix[j++] = s[top--];
    }
    postfix[j] = '\0';
    return;
}