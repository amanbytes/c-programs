//Program to count total number of lead nodes in the tree

#include<stdio.h>
#include<stdlib.h>

#define new_node (struct node *)malloc(sizeof(struct node))

struct node {
    int data;
    struct node *l,*r;
};

struct node * create_bin_tree();
void print_bin_tree(struct node *temp);
void count_leaf_nodes(struct node *temp,int *l, int *nl);

int main()
{
    struct node *root;
    int leaf,nonleaf;

    printf("\nCreating a binary tree:");

    root= create_bin_tree();

    printf("\nCreated binary tree:");
    print_bin_tree(root);

    leaf=nonleaf=0;
    count_leaf_nodes(root,&leaf,&nonleaf);
    printf("\nTotal number of leaf nodes are: %d",leaf);
    printf("\nTotal number of non-leaf nodes are: %d",nonleaf);
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

void count_leaf_nodes(struct node *temp,int *leaf, int *notleaf)
{

    if(temp!=NULL)
    {
        if(temp->l==NULL && temp->r==NULL)
        (*leaf)++;
        else
        (*notleaf)++;
        count_leaf_nodes(temp->l,leaf,notleaf);
        count_leaf_nodes(temp->r,leaf,notleaf);
    }
}