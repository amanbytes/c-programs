//Program to compare two trees

#include<stdio.h>
#include<stdlib.h>

#define new_node (struct node *)malloc(sizeof(struct node))

struct node {
    int data;
    struct node *l,*r;
};

struct node * create_bin_tree();
void print_bin_tree(struct node *temp);
int compare(struct node *tree1,struct node *tree2);
static int more=1;

int main()
{
    struct node *root1,*root2;
    int reply;

    printf("\nCreating first binary tree:");
    root1= create_bin_tree();
    more=1;
    printf("\nCreating second binary tree:");
    root2= create_bin_tree();

    printf("\nFirst binary tree:");
    print_bin_tree(root1);

    printf("\nSecond binary tree:");
    print_bin_tree(root2);

    reply=compare(root1,root2);
    if (reply==1)
    printf("\nBoth Tress are same");
    else
    printf("\nOops These two are not same");
    return(1);
}

struct node * create_bin_tree()
{
    int data;
    struct node *t;
    if(more==1)
    {
        printf("\nEnter the data : ");
        scanf("%d",&data);
    }
    else
    data = -1;
    if(data==-1)
    {
        more=0;
        return(NULL);
    }
    else
    {
        t=new_node;
        t->data=data;
        t->l=create_bin_tree();
        t->r=create_bin_tree();
        return(t);
    }
}

void print_bin_tree(struct node *temp) {
    if(temp!=NULL)
    {
        printf("%d ",temp->data);
        print_bin_tree(temp->l);
        print_bin_tree(temp->r);
    }

}

int compare(struct node *tree1,struct node *tree2)
{
    int reply;
    if(tree1==NULL && tree2==NULL)
    return 1;
    else if(tree1 !=NULL && tree2 == NULL)
    return 0;
    else if(tree1==NULL && tree2 != NULL)
    return 0;
    else if(tree1->data != tree2->data)
    return 0;
    else
    {
        reply=compare(tree1->l,tree2->l);
        if(reply==1)
        reply=compare(tree1->r,tree2->r);
        return reply;
    }
}