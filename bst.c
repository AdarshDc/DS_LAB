#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};
typedef struct node *NODE;
NODE root = NULL;
void insert()
{
    NODE newnode, prev, curr;
    newnode = (NODE)malloc(sizeof(struct node));
    printf("Enter the element to be inserted in tree\n");
    scanf("%d", &newnode->data);
    newnode->lchild = newnode->rchild = NULL;
    if (root == NULL)
    {
        root = newnode;
        return;
    }
    prev = NULL;
    curr = root;
    while (curr != NULL)
    {
        if (curr->data == newnode->data)
        {
            printf("Duplicate is not possible\n");
            free(newnode);
            return;
        }
        prev = curr;
        if (newnode->data < curr->data)
            curr = curr->lchild;
        else
            curr = curr->rchild;
    }
    if (newnode->data < prev->data)
        prev->lchild = newnode;
    else
        prev->rchild = newnode;
    return;
}
void search(NODE root)
{
    int key;
    NODE curr;
    printf("Enter the element to be searched \n");
    scanf("%d", &key);
    if (root == NULL)
    {
        printf("tree is empty\n");
        return;
    }
    curr = root;
    while (curr != NULL)
    {
        if (curr->data == key)
        {
            printf("Number found\n");
            return;
        }
        if (key < curr->data)
            curr = curr->lchild;
        else
            curr = curr->rchild;
    }
    printf("Number not found\n");
    return;
}
void inorder(NODE root)
{
    if (root != NULL)
    {
        inorder(root->lchild);
        printf("%4d", root->data);
        inorder(root->rchild);
    }
    return;
}
void preorder(NODE root)
{
    if (root != NULL)
    {
        printf("%4d", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
    return;
}
void postorder(NODE root)
{
    if (root != NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%4d", root->data);
    }
    return;
}
void display(NODE root, int level)
{
    int i;
    if (root)
    {
        display(root->rchild, level + 1);
        printf("\n");
        for (i = 0; i < level; i++)
            printf("\t");
        printf("%d", root->data);
        display(root->lchild, level + 1);
    }
    return;
}
void del_item(NODE root, int item)
{
    NODE cur, parent, suc, q;
    if (root == NULL)
    {
        printf("Tree is empty! Item not found\n");
        return;
    }
    parent = NULL;
    cur = root;
    while (cur != NULL)
    {
        if (item == cur->data)
            break;
        parent = cur;
        if (item < cur->data)
            cur = cur->lchild;
        else
            cur = cur->rchild;
    }
    if (cur == NULL)
    {
        printf("Item not found\n");
        return;
    }
    if (cur->lchild == NULL)
        q = cur->rchild;
    else if (cur->rchild == NULL)
        q = cur->lchild;
    else
    {
        suc = cur->rchild;
        while (suc->lchild != NULL)
            suc = suc->lchild;
        suc->lchild = cur->lchild;
        q = cur->rchild;
    }
    if (parent == NULL)
    {
        root = q;
        return;
    }
    if (cur == parent->lchild)
        parent->lchild = q;
    else
        parent->rchild = q;
    free(cur);
    return;
}
void main()
{
    int ch, i, n, item;
    NODE res;
    for (;;)
    {
        printf("\n**TREE OPERATIONS ARE**\n");
printf (" 1:Insert node\n 2:Inorder traversal\n 3:Preorder traversal\n 4:Postorder traversal\n5:Display\n 6:Search\n 7:Delete an item from the tree\n 8:Exit"); 
printf("\n*********\n"); printf("\nEnter your choice:\n");
scanf("%d",&ch);
switch(ch)
{
        case 1:
            printf("Enter the no of elements\n");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
                insert();
            break;
        case 2:
            if (root == NULL)
                printf("Empty tree\n");
            else
            {
                printf("Inorder traversal\n");
                inorder(root);
            }
            break;
        case 3:
            if (root == NULL)
                printf("Empty tree\n");
            else
            {
                printf("preorder traversal\n");
                preorder(root);
            }
            break;
        case 4:
            if (root == NULL)
                printf("Emtpy tree\n");
            else
            {
                printf("Postorder traversal\n");
                postorder(root);
            }
            break;
        case 5:
            if (root == NULL)
                printf("Empty tree\n");
            else
                printf("The tree is:\n");
            display(root, 1);
            break;
        case 6:
            search(root);
            break;
        case 7:
            printf("Enter the node to be deleted\n");
            scanf("%d", &item);
            del_item(root, item);
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice\n");
}
    }
}
