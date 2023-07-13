#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 5
int front = 0, rear = -1, count = 0;
char cq[MAX], ele;
void insert();
void display();
void delete();
void main()
{
    int choice;
    while (1)
    {
        printf("\n\t1=>insert an element on to CIRCULAR QUEUE\n\t2=>delete an element from CIRCULAR QUEUE\n\t3=>display the status of CIRCULAR QUEUE\n\t4=>exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Enter a valid choice\n");
        }
    }
}
void insert()
{
    if (count == MAX)
    {
        printf("Circular Queue is full, elements cannot be inserted\n");
        return;
    }
    rear = (rear + 1) % MAX;
    printf("\nenter the element to be inserted into the Circular Queue\n");
    ele = getche();
    cq[rear] = ele;
    count++;
}
void delete()
{
    if (count == 0)
    {
        printf("Circular Queue is empty, no elements to delete\n");
        return;
    }
    ele = cq[front];
    front = (front + 1) % MAX;
    printf("the element deleted is%c\n", ele);
    count--;
}
void display()
{
    int i;
    if (count == 0)
    {
        printf("CIRCULAR QUEUE is empty,no element to display\n");
        return;
    }
    printf("Circular Queue contents are\n");
    for (i = front; i != rear; i = (i + 1) % MAX)
    {
        printf("%c\t", cq[i]);
    }
    printf("%c", cq[i]);
}