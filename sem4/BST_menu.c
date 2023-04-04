//BST with create,search,insert,inorder,preorder and postorder.

#include<stdio.h>
#include<stdlib.h>

#define new_node (struct BSTnode *)malloc(sizeof(struct BSTnode))

struct BSTnode {
    int data;
    struct BSTnode *l,*r;
};

struct BSTnode * create();
struct BSTnode * insert(struct BSTnode *temp, int data);
struct BSTnode * search(struct BSTnode *temp, int data);
void preorder(struct BSTnode *temp);
void inorder(struct BSTnode *temp);
void postorder(struct BSTnode *temp);

int main()
{
    struct BSTnode *tree1=NULL;
    int cont;
    printf("\nCreating binary tree:");
    tree1= create();
    do
    {
        printf("\nWhat do you want to do ?");
        printf("\n1. Print Perorder");
        printf("\n2. Print Inorder");
        printf("\n3. Print Postorder");
        printf("\n4. Search Element");
        printf("\n5. Insert a element");
        printf("\n6.Exit");
        printf("\n-> ");
        scanf("%d",&cont);
        switch (cont)
        {
        case 1 :
                printf("\nPreorder of the tree is : "); 
                preorder(tree1);
                printf("\n");
                break;
        case 2 :
                printf("\nInorder of the tree is : "); 
                inorder(tree1);
                printf("\n");
                break;
        case 3 :
                printf("\nPostorder of the tree is : "); 
                postorder(tree1);
                printf("\n");
                break;
        case 4 : 
                int key;
                printf("\nEnter the element to search: ");
                scanf("%d",&key);
                struct BSTnode *ele = NULL;
                ele = search(tree1,key);
                ele == NULL ? printf ("\nElement is not in the BST") : printf("\n Element found, address is %u\n",ele);
                break;
        case 5 :
                int data;
                printf("\nEnter the data to insert : ");
                scanf("%d",&data);
                insert(tree1,data);
                printf("\nInsertion completed!!\n");
                break;
        case 6 : exit(0);
        }
    } while (1);
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

struct BSTnode * search(struct BSTnode *temp, int data)
{
    int num;
    if (temp!=NULL)
    num=temp->data;
    if(temp!=NULL)
    {
        return (data==num) ? temp : data<num ? search(temp->l,data): search(temp->r,data);
    }
    else 
        return  NULL;
}


void preorder(struct BSTnode *temp)
{
    if (temp != NULL)
    {
        printf("%d ", temp->data);
        preorder(temp->l);
        preorder(temp->r);
    }
}

void inorder(struct BSTnode *temp)
{
    if (temp != NULL)
    {
        inorder(temp->l);
        printf("%d ", temp->data);
        inorder(temp->r);
    }
}

void postorder(struct BSTnode *temp)
{
    if (temp != NULL)
    {
        postorder(temp->l);
        postorder(temp->r);
        printf("%d ", temp->data);
    }
}