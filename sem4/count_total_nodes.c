//Program to count total number of nodes in the tree

#include<stdio.h>
#include<stdlib.h>

#define new_node (struct node *)malloc(sizeof(struct node))

struct node {
    int data;
    struct node *l,*r;
};

struct node * create_bin_tree();
void print_bin_tree(struct node *temp);
struct node * copy_bin_tree(struct node * temp);
int count_nodes(struct node *temp);

int main()
{
    struct node *root;
    int total_nodes=0;

    printf("\nCreating a binary tree:");

    root= create_bin_tree();

    printf("\nCreated binary tree:");
    print_bin_tree(root);

    total_nodes = count_nodes(root);
    printf("\nTotal number of nodes are: %d",total_nodes);
    return(1);
}

struct node * create_bin_tree()
{
    int data;
    static int more=1;
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

int count_nodes(struct node *temp)
{
    static int count=0;
    if(temp!=NULL)
    {
        count++;
        count_nodes(temp->l);
        count_nodes(temp->r);
    }
    return count;
}