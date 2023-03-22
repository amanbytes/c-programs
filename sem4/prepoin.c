#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *l, *r;
} *start, *temp, *temp1;

int no, n, i;

void preorder(struct node *temp);
void inorder(struct node *temp);
void postorder(struct node *temp);

int main()
{

    printf("Enter the number of nodes: ");
    scanf("%d", &no);
    printf("Enter the number: ");
    scanf("%d", &n);
    start = (struct node *)malloc(sizeof(struct node));
    start->data = n;
    start->l = NULL;
    start->r = NULL;
    for (i = 1; i < no; i++)
    {
        scanf("%d", &n);
        for (temp = start; temp != NULL;)
        {
            temp1 = temp;
            if (n < temp1->data)
                temp = temp1->l;
            else
                temp = temp1->r;
        }
        if (n < temp1->data)
        {
            temp1->l = (struct node *)malloc(sizeof(struct node));
            temp1 = temp1->l;
        }
        else
        {
            if (n >= temp1->data)
            {
                temp1->r = (struct node *)malloc(sizeof(struct node));
                temp1 = temp1->r;
            }
        }
        temp1->data = n;
        temp1->l = NULL;
        temp1->r = NULL;
    }
    printf("\n The pre-order:\n");
    preorder(start);
    printf("\n The in-order:\n");
    inorder(start);
    printf("\n The post-order:\n");
    postorder(start);
    return (0);
}

void preorder(struct node *temp)
{
    if (temp != NULL)
    {
        printf("%d ", temp->data);
        preorder(temp->l);
        preorder(temp->r);
    }
}

void inorder(struct node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->l);
        printf("%d ", temp->data);
        inorder(temp->r);
    }
}

void postorder(struct node *temp)
{
    if (temp != NULL)
    {
        postorder(temp->l);
        postorder(temp->r);
        printf("%d ", temp->data);
    }
}
