#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    char ssn[25], name[25], dept[10], designation[25];
    long int sal, phoneno;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;
NODE first = NULL;
int count = 0;
NODE getNode()
{
    NODE newnode;
    newnode = (NODE)malloc(sizeof(struct node));
    printf("\nEntertheEmployeessn,Name,Dept,Designation,Salary,PhoneNo\n");
    scanf("%s%s%s%s%ld%ld", newnode->ssn, newnode->name, newnode->dept, newnode->designation, &newnode->sal, &newnode->phoneno);
    if (newnode == NULL)
    {
        printf("\nRunning out of memory");
        exit(0);
    }
    newnode->llink = NULL;
    newnode->rlink = NULL;
    count++;
    return newnode;
}
void insertAtFront()
{
    NODE temp;
    temp = getNode();
    if (first == NULL)
    {
        first = temp;
        return;
    }
    temp->rlink = first;
    first->llink = temp;
    first = temp;
    return;
}
void deleteAtFront()
{
    NODE temp;
    if (first == NULL)
    {
        printf("\nDoubly Linked List is empty");
        return;
    }
    temp = first;
    first = first->rlink;
    temp->rlink = NULL;
    first->llink = NULL;
    printf("\nThe employee node with the ssn:%sis deleted", temp->ssn);
    free(temp);
    count--;
    return;
}
void insertAtEnd()
{
    NODE cur, temp;
    temp = getNode();
    if (first == NULL)
    {
        first = temp;
        return;
    }
    cur = first;
    while (cur->rlink != NULL)
    {
        cur = cur->rlink;
    }
    cur->rlink = temp;
    temp->llink = cur;
    return;
}
void deleteAtEnd()
{
    NODE prev, cur;
    if (first == NULL)
    {
        printf("\nDoubly Linked List is empty");
        return;
    }
    if (first->rlink == NULL)
    {
        printf("\nThe employee node with the ssn:%s is deleted", first->ssn);
        free(first);
        first = NULL;
        count--;
        return;
    }
    prev = NULL;
    cur = first;
    while (cur->rlink != NULL)
    {
        prev = cur;
        cur = cur->rlink;
    }
    cur->llink = NULL;
    printf("\nThe employee node with the ssn:%s is deleted", cur->ssn);
    free(cur);
    prev->rlink = NULL;
    count--;
    return;
}
void displayStatus()
{
    NODE cur;
    int nodeno = 1;
    if (first == NULL)
    {
        printf("\nNo Contents to display in DLL");
        return;
    }
    printf("\nENode||SSN|Name|Department|Designation|Salary|Phone\n");
    cur = first;
    while (cur != NULL)
    {
        printf("\n%d||%s|%s|%s|%s|%ld|%ld", nodeno, cur->ssn, cur->name, cur->dept, cur->designation, cur->sal, cur->phoneno);
        cur = cur->rlink;
        nodeno++;
    }
    printf("\nNo of employee nodes is%d", count);
}
void doubleEndedQueueDemo()
{
    int ch;
    while (1)
    {
        printf("\nDemo Double Ended Queue Operation");
        printf("\n1:Insert Queue Front\n2:Delete Queue Front\n3:Insert Queue Rear\n 4:Delete Queue Rear\n5:Display Status\n6:Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertAtFront();
            break;
        case 2:
            deleteAtFront();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            deleteAtEnd();
            break;
        case 5:
            displayStatus();
            break;
        case 6:
            return;
        default:
            printf("invalid choice\n");
        }
    }
}
void main()
{
    int ch, i, n;
    while (1)
    {
        printf("\n~~~Menu~~~");
        printf("\nEnter your choice for DLL operation\n");
        printf("\n1:Create DLL of employ Nodes");
        printf("\n2:Display Status");
        printf("\n3:double Ended Queue Demo");
        printf("\n4:Exit\n");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the no of Employees:");
            scanf("%d", &n);
            for (i = 1; i <= n; i++)

                insertAtEnd();
            break;

        case 2:
            displayStatus();
            break;
        case 3:
            doubleEndedQueueDemo();
            break;
        case 4:
            exit(0);
        default:
            printf("\nEnter the valid choice");
        }
    }
}
