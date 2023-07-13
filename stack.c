#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int s[MAX];
int top = -1;
void push();
void pop();
void palindrome();
void display();
void main()
{
    int ch;
    while (1)
    {
        printf("\nMENU:\n1.push\n2.pop\n3.palindrome\n4.dispaly\n5.Exit\nenter your choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            palindrome();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;

        default:
            printf("enter the valid choice\n");
        }
    }
}
void push()
{
    int ele;
    if (top == MAX - 1)
    {
        printf("stack overflow\n");
        return;
    }
    printf("enter an element to be pushed\n");
    scanf("%d", &ele);
    top = top + 1;
    s[top] = ele;
    return;
}
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("Element popped is %d \n", s[top]);
    top = top - 1;
    return;
}
void display()
{
    int i;
    if (top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack elements are\n");
    for (i = top; i >= 0; i--)
        printf("| %d |\n", s[i]);
    return;
}
void palindrome()
{
    int flag = 1, i;
    for (i = 0; i <= top / 2; i++)
    {
        if (s[i] != s[top - i])
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
        printf("It is palindrome\n");
    else
        printf("Not a palindrome\n");
}