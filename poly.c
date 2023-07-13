#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    int coef, xexp, yexp, zexp;
    struct node *link;
};
typedef struct node *NODE;
void display(NODE head)
{
    NODE temp;
    temp = head->link;
    while (temp != head)
    {
        if (temp->coef < 0)
            printf("%dx^%d y^%d z^%d ", temp->coef, temp->xexp, temp->yexp, temp->zexp);
        else
            printf("+%dx^%d y^%d z^%d ", temp->coef, temp->xexp, temp->yexp, temp -> zexp);
        temp = temp->link;
    }
    printf("\n");
}
NODE attach(int coef, int xexpon, int yexpon, int zexpon, NODE head)
{
    NODE temp, cur;
    temp = (NODE)malloc(sizeof(struct node));
    temp->coef = coef;
    temp->xexp = xexpon;
    temp->yexp = yexpon;
    temp->zexp = zexpon;
    cur = head->link;
    while (cur->link != head)
        cur = cur->link;
    cur->link = temp;
    temp->link = head;
    return head;
}
NODE readpoly(NODE head)
{
    int i = 1, coef, xexpon, yexpon, zexpon;
    printf("enter the coefficient as -99 to end the polynomial\n");
    while (1)
    {
        printf("enter the %d term of the polynomial\n", i++);
        printf("enter the coefficient:\n");
        scanf("%d", &coef);
        if (coef == -99)
            break;
        printf("enter the xexponent:\n");
        scanf("%d", &xexpon);
        printf("enter the yexponent:\n");
        scanf("%d", &yexpon);
        printf("enter the zexponent:\n");
        scanf("%d", &zexpon);
        head = attach(coef, xexpon, yexpon, zexpon, head);
    }
    display(head);
    return head;
}
int evaluate(NODE head)
{
    NODE temp;
    int x, y, z, value = 0;
    temp = head->link;
    printf("Enter the value of x,y and z\n");
    scanf("%d%d%d", &x, &y, &z);
    while (temp != head)
    {
        value = value + temp->coef * (pow(x, temp->xexp) * pow(y, temp->yexp) * pow(z, temp -> zexp));
        temp = temp->link;
    }
    return value;
}
NODE addpoly(NODE head1, NODE head2, NODE head3)
{
    NODE a, b;
    int sum;
    a = head1->link;
    b = head2->link;
    while (a != head1 && b != head2)
    {
        if (a->xexp == b->xexp)
        {
            if (a->yexp == b->yexp)
            {
                if (a->zexp == b->zexp)
                {
                    sum = a->coef + b->coef;
                    attach(sum, a->xexp, a->yexp, a->zexp, head3);
                    a = a->link;
                    b = b->link;
                }
                else if (a->zexp > b->zexp)
                {
                    attach(a->coef, a->xexp, a->yexp, a->zexp, head3);
                    a = a->link;
                }
                else
                {
                    attach(b->coef, b->xexp, b->yexp, b->zexp, head3);
                    b = b->link;
                }
            }
            else if (a->yexp > b->yexp)
            {
                attach(a->coef, a->xexp, a->yexp, a->zexp, head3);
                a = a->link;
            }
            else
            {
                attach(b->coef, b->xexp, b->yexp, b->zexp, head3);
                b = b->link;
            }
        }
        else if (a->xexp > b->xexp)
        {
            attach(a->coef, a->xexp, a->yexp, a->zexp, head3);
            a = a->link;
        }
        else
        {
            attach(b->coef, b->xexp, b->yexp, b->zexp, head3);
            b = b->link;
        }
    }
    while (a != head1)
    {
        head3 = attach(a->coef, a->xexp, a->yexp, a->zexp, head3);
        a = a->link;
    }
    while (b != head2)
    {
        head3 = attach(b->coef, b->xexp, b->yexp, b->zexp, head3);
        b = b->link;
    }
    return head3;
}
void main()
{
    int ch;
    NODE head, head1, head2, head3;
    head = (NODE)malloc(sizeof(struct node));
    head1 = (NODE)malloc(sizeof(struct node));
    head2 = (NODE)malloc(sizeof(struct node));
    head3 = (NODE)malloc(sizeof(struct node));
    while (1)
    {
        printf("\n1.Polynomial Evaluation \n2.Polynomial Addition \n3.Exit\n");
        printf("\nEnter the choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            head->link = head;
            printf("Enter the polynomial\n");
            readpoly(head);
            printf("The result of polynomial is:%d", evaluate(head));
            break;
        case 2:
            head1->link = head1;
            head2->link = head2;
            head3->link = head3;
            printf("Enter the first polynomial\n");
            readpoly(head1);
            printf("\nEnter the second polynomial\n");
            readpoly(head2);
            printf("\nthe first polynomial is:");
            display(head1);
            printf("\nthe second polynomial is:");
            display(head2);
            addpoly(head1, head2, head3);
            printf("\nthe result of adding two polynomials is:");
            display(head3);
            break;
        case 3:
            exit(0);
        }
    }
}
