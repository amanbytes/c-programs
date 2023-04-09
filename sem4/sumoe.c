//BST Program to sum even and odd elements

#include<stdio.h>
#include<stdlib.h>

#define new_node (struct BSTnode *)malloc(sizeof(struct BSTnode))

struct BSTnode {
    int data;
    struct BSTnode *l,*r;
};

int result=0;

struct BSTnode * create();
struct BSTnode * insert(struct BSTnode *temp, int data);
void print_tree(struct BSTnode *temp);
int sum_even(struct BSTnode *temp);
void sum_odd(struct BSTnode *temp);

int main()
{
    struct BSTnode *tree1=NULL;
    printf("\nCreating binary tree :");
    tree1= create();
    printf("\nBinary tree:");
    print_tree(tree1);
    result=0;
    sum_odd(tree1);
    printf("\nSum of odd nodes is : %d",result);
    result=0;
    sum_even(tree1);
    printf("\nSum of even nodes is : %d",result);
    return(1);
}

struct BSTnode * create()
{
    int no,data;
    struct BSTnode *t=NULL;
    printf("\nHow many nodes? : ");
    scanf("%d",&no);
    printf("\nEnter the data for nodes: ");
    for(int i=0;i<no;i++)
    {
        scanf("%d",&data);
        t=insert(t,data);
    }
    return t;
}

struct BSTnode * insert(struct BSTnode *temp, int data)
{
  if (temp==NULL)
  { temp=new_node;
    temp->data=data;
    temp->l=NULL;
    temp->r=NULL;
  }
  else
  if(data > temp->data)
  { temp->r=insert(temp->r,data);
    return(temp);
  }
  else
   temp->l=insert(temp->l,data);
  return(temp);
}

void print_tree(struct BSTnode *temp) {
    if(temp!=NULL)
    {
        printf("%d ",temp->data);
        print_tree(temp->l);
        print_tree(temp->r);
    }

}

int sum_even(struct BSTnode *temp)
{
    if(temp!=NULL)
    {
        if(temp->data%2==0)
        result+=temp->data;
        sum_even(temp->l);
        sum_even(temp->r);
    }

}

void sum_odd(struct BSTnode *temp)
{
    if(temp!=NULL)
    {
        if(temp->data%2!=0)
        result+=temp->data;
        sum_odd(temp->l);
        sum_odd(temp->r);
    }
}
