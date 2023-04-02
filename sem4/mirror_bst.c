//BST Program
// Print,Copy,Check_Mirror,Leaf_Count

#include<stdio.h>
#include<stdlib.h>

#define new_node (struct BSTnode *)malloc(sizeof(struct BSTnode))

struct BSTnode {
    int data;
    struct BSTnode *l,*r;
};

struct BSTnode * create();
struct BSTnode * insert(struct BSTnode *temp, int data);
int check_mirror(struct BSTnode *tree1,struct BSTnode *tree2);
int count_leaf(struct BSTnode *temp);
void print_tree(struct BSTnode *temp);
struct BSTnode *tree_copy(struct BSTnode *temp);

int main()
{
    struct BSTnode *tree1=NULL,*tree2=NULL;
    int n1,n2;

    printf("\nCreating first binary tree:");
    tree1= create();

    printf("\nCreating second binary tree:");
    tree2= create();

    printf("\nFirst binary tree:");
    print_tree(tree1);

    printf("\nSecond binary tree:");
    print_tree(tree2);

    if(check_mirror(tree1,tree2))
    printf("\nBoth are mirror image of each other");
    else
    printf("\nBoth are not mirror image of each other");

    n1=count_leaf(tree1);
    n2=count_leaf(tree2);
    printf("\nTotal number of leaf nodes in first treee are: %d ",n1);
    printf("\nTotal number of leaf nodes in second treee are: %d ",n2);

    tree2=tree_copy(tree1);
    printf("\nCopied first tree on tree2\n");
    print_tree(tree2);
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

int check_mirror(struct BSTnode *tree1,struct BSTnode *tree2)
{
  int response;
  if(tree1==NULL && tree2==NULL)
    return 1;
  else
  if(tree1->data==tree2->data)
  {
    response = check_mirror(tree1->l,tree2->l) && check_mirror(tree1->r,tree2->r);
    return response;
  }
  else
    return 0;
}


int count_leaf(struct BSTnode *temp)
{
  if (temp==NULL)
    return 0;
  else
  if(temp->l==NULL && temp->r==NULL)
    return 1;
  else
    return count_leaf(temp->l) + count_leaf(temp->r);

}


struct BSTnode *tree_copy(struct BSTnode *temp)
{
  struct BSTnode *tt;
  if(temp==NULL)
    return(NULL);
  else
  {
    tt=new_node;
    tt->data=temp->data;
    tt->l=tree_copy(temp->l);
    tt->r=tree_copy(temp->r);
    return(tt);
  }
}

void print_tree(struct BSTnode *temp) {
    if(temp!=NULL)
    {
        printf("%d ",temp->data);
        print_tree(temp->l);
        print_tree(temp->r);
    }

}