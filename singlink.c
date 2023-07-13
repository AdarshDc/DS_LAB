#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    char usn[25], name[25], branch[25];
    int sem;
    long int phone;
    struct node *link;
};
typedef struct node *NODE;
NODE first;
int count = 0;
NODE getNode()
{
    NODE newnode;
    char usn[20], name[20], branch[20];
    int sem;
    long int phone;
    printf("\nEnter the usn, Name, Branch, sem, PhoneNo ofthe student: \n");
    scanf("%s %s %s %d %ld", usn, name, branch, &sem, &phone);
    newnode = (NODE)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("\nMemory is not available");
        exit(0);
    }
    strcpy(newnode->usn, usn);
    strcpy(newnode->name, name);
    strcpy(newnode->branch, branch);
    newnode->sem = sem;
    newnode->phone = phone;
    count++;
    return newnode;
}
void insertAtFront()
{
    NODE temp;
    temp = getNode();
    temp->link = first;
    first = temp;
    return;
}
void deleteAtFront()
{
    NODE temp;
    if (first == NULL)
    {
        printf("\nLinked list is empty");
        return;
    }
    if (first->link == NULL)
    {
        printf("\nThe Student node with usn:%s is deleted ", first->usn);
        count--;
        free(first);
        first = NULL;
        return;
    }
    temp = first;
    first = first->link;
    printf("\nThe Student node with usn:%s is deleted", temp->usn);
    count--;
    free(temp);
    return;
}
void insertAtEnd()
{
    NODE cur, temp;
    temp = getNode();
    temp->link = NULL;
    if (first == NULL)
    {
        first = temp;
        return;
    }
    if (first->link == NULL)
    {
        first->link = temp;
        return;
    }
    cur = first;
    while (cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = temp;
    return;
}
void deleteAtEnd()
{
    NODE cur, prev;
    if (first == NULL)
    {
        printf("\nLinked List is empty");
        return;
    }
    if (first->link == NULL)
    {
        printf("\nThe student node with the usn:%s is deleted\n", first->usn);
        free(first);
        first = NULL;
        count--;
        return;
    }
    prev = NULL;
    cur = first;
    while (cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }
    printf("\nThe student node with the usn:%s is deleted", cur->usn);
    free(cur);
    prev->link = NULL;
    count--;
    return;
}
void displayStatus()
{
    NODE cur;
    int nodeNo = 1;
    if (first == NULL)
    {
        printf("\nNo Contents to display in SLL \n");
        return;
    }
    printf("\nThe contents of SLL: \n");
    cur = first;
    while (cur != NULL)
    {
        printf("\n||%d||", nodeNo);
        printf(" USN:%s|", cur->usn);
        printf(" Name:%s|", cur->name);
        printf(" Branch:%s|", cur->branch);
        printf(" Sem:%d|", cur->sem);
        printf(" Ph:%ld|", cur->phone);
        cur = cur->link;
        nodeNo++;
    }
    printf("\n No of student nodes is %d \n", count);
}
void stackDemoUsingSLL()
{
    int ch;
    while (1)
    {
        printf("\n~~~Stack Demo using SLL~~~\n");
        printf("\n1:Push operation \n2: Pop operation \n3: Display\n4:Exit \n");
        printf("\nEnter your choice for stack demo");
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
            displayStatus();
            break;
        case 4:
            return;
        }
    }
}
void main()
{
    int ch, i, n;
    while (1)
    {
        printf("\n~~~Menu~~~");
        printf("\nEnter your choice for SLL operation \n");
        printf("\n1:Create SLL of Student Nodes");
        printf("\n2:DisplayStatus");
        printf("\n3:InsertAtEnd");
        printf("\n4:DeleteAtEnd");
        printf("\n5:Stack Demo using SLL(Insertion and Deletion at Front)");
        printf("\n6:Exit \n");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the no of students: ");
            scanf("%d", &n);
            for (i = 1; i <= n; i++)
                insertAtFront();
            break;
        case 2:
            displayStatus();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            deleteAtEnd();
            break;
        case 5:
            stackDemoUsingSLL();
            break;
        case 6:
            exit(0);
        default:
            printf("\nEnter the valid choice");
        }
    }
}