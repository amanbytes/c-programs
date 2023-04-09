//BST with create,search,insert,inorder,preorder and postorder.

#include<stdio.h>
#include<stdlib.h>
#include"btree.h"

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
        printf("\n6. Print Tree");
        printf("\n7.Exit");
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
                struct reply elu;
                reset(elu);
                elu = search(tree1,key);
                elu.ele == NULL ? printf ("\nElement is not in the BST") : printf("\nElement found, address is %u\nLevel/Depth is %d",elu.ele,elu.pos-1);
                break;
        case 5 :
                int data;
                printf("\nEnter the data to insert : ");
                scanf("%d",&data);
                insert(tree1,data);
                printf("\nInsertion completed!!\n");
                break;
        case 6 :
                print_ascii_tree(tree1);
                break;
        case 7 : exit(0);
        }
    } while (1);
}
