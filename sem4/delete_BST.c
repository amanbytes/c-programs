// BST Delete a node

#include <stdio.h>
#include<stdlib.h>

#define new_node ( struct node*)malloc(sizeof(struct node))

struct node
{
	int data;
	struct node *lc,*rc;
};

struct node *insert_data(struct node *root, int n );
struct node *delete_data(struct node *root, int n );
int inorder( struct node *t);

void main()
{
	struct node *root;
	int option,data;
	root = NULL;
	do
	{
		printf("\n1. Insert data ");
		printf("\n2. Print data ");
		printf("\n3. Delete data");
		printf("\n4. exit");
		printf("\n\nSelect a proper option : ");
		scanf("%d",&option);
		switch( option)
		{
			case 1 : // insert
						printf("\nEnter insertion data : ");
						scanf("%d",&data);
						root = insert_data(root,data);
						break;
			case 2 : // print
					if( root == NULL)
							printf("\nTree is empty");
					else
					{
							printf("\nInorder output is: ");
							inorder(root);
					}
						break;
			case 3 : // delete
						if( root == NULL)
						{
							printf("\n Tree is empty");
						}
						else
						{
							printf("\n Enter data to be deleted : ");
							scanf("%d",&data);
							root = delete_data(root,data);
						}
						break;
			case 4 :   exit(0);
		} 
	} while(1);
}

struct node *insert_data(struct node *root, int n )
{
	struct node *c,*p,*q;
	c = new_node;
	c->data = n;
	c->lc = c->rc = NULL;
	//.... find proper position for new node
	if( root == NULL )
		root = c;
	else
	{
		q = NULL;
		p = root;
		while( p != NULL)
		{
			if( c->data < p->data )
			{
					q = p;
					p = p->lc;
			}
			else
			{
					q = p;
					p = p->rc;
			}
		}
		if( c->data < q->data)
				q->lc = c;
		else
				q->rc = c;
	}
	return(root);
}

struct node *delete_data(struct node *root, int n )
{
	struct node *c,*p,*q,*t1,*t2;

	p = root;

	if(p->data == n) 
	{
		if( p->lc == NULL && p->rc == NULL)
		{
			free(p);
			return(NULL);
		}
		else
		if( p->lc != NULL && p->rc == NULL)
		{
			root = p->lc;
			free(p);
			return(root);
		}
		else
		if( p->lc == NULL && p->rc != NULL)
		{
			root = p->rc;
			free(p);
			return(root);
		}
		else
		{
			t1 = p->lc;
			while( t1 != NULL)
			{
				t2 = t1;
				t1 = t1->rc;
			}
			t2->rc = p->rc;
			root = p->lc;
			free(p);
			return(root);
		} //else
	}
	p = root;
	q = NULL;
	while( p ->data != n && p != NULL)
	{
		if( n < p->data )
		{
			q = p;
			p = p->lc;
		}
		else
		if( n > p->data )
		{
			q = p;
			p = p->rc;
		}
		else
			break;
	} 
	if( p == NULL)
	{
		printf("\nSearch data not found");
		return(root);
	}
	if ( p->lc == NULL && p->rc == NULL )  //... p is leaf node
	{
		if( p->data < q->data )
			q->lc = NULL;
		else
			q->rc = NULL;
		free(p);
		return(root);
	}
	else
	if ( p->lc != NULL && p->rc == NULL )  //... p is non leaf node with non-null lc
	{
		if( p->data < q->data )
			q->lc = p->lc;
		else
			q->rc = p->lc;
		free(p);
		return(root);
	}
	else
	if ( p->lc == NULL && p->rc != NULL )  //... p is non leaf node with non-null rc
	{
		if( p->data < q->data )
			q->lc = p->rc;
		else
			q->rc = p->rc;
		free(p);
		return(root);
	}
	else
	{
		t1 = p->lc;
		while( t1 != NULL)
		{
			t2 = t1;
			t1 = t1->rc;
		}
		t2->rc = p->rc;

		if( p->data < q->data )
			q->lc = p->lc;
		else
			q->rc = p->lc;
		free(p);
		return(root);
	}

} // insert data

int inorder( struct node *t)
{
	if( t != NULL)
	{
		inorder(t->lc);
		printf("%4d",t->data);
		inorder(t->rc);
	} //if
	return(0);
}// inorder