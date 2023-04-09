#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define new_node (struct BSTnode *)malloc(sizeof(struct BSTnode))
#define MAX_HEIGHT 1000
#define INFINITY 1000

int print_next = 0;
int gap = 3;
int lprofile[MAX_HEIGHT];
int rprofile[MAX_HEIGHT];


struct BSTnode {
    int data;
    struct BSTnode *l,*r;
};

struct reply {
    int pos;
    struct BSTnode *ele;
} temp_reply;


struct asciinode_struct
{
  struct asciinode_struct * left, * right;

  //length of the edge from this node to its children
  int edge_length;

  int height;

  int lablen;

  //-1=I am left, 0=I am root, 1=right
  int parent_dir;

  //max supported unit32 in dec, 10 digits max
  char label[11];
};


struct BSTnode * create();
struct BSTnode * insert(struct BSTnode *temp, int data);
struct reply search(struct BSTnode *temp, int data);
void preorder(struct BSTnode *temp);
void inorder(struct BSTnode *temp);
void postorder(struct BSTnode *temp);
int getLevelCount(struct BSTnode *node);
void print_level(struct asciinode_struct *node, int x, int level);
void compute_edge_lengths(struct asciinode_struct *node);
struct asciinode_struct * build_ascii_tree_recursive(struct BSTnode * t);
struct asciinode_struct * build_ascii_tree(struct BSTnode * t);
void free_ascii_tree(struct asciinode_struct *node);
void compute_lprofile(struct asciinode_struct *node, int x, int y);
void compute_rprofile(struct asciinode_struct *node, int x, int y);
void print_ascii_tree(struct BSTnode * t);
int MIN(int a, int b);
int MAX(int a, int b);
//Resetting the values of temp_reply so the dept does not get incremented with previous value
void reset(struct reply a);

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
  if(data >= temp->data)
  { temp->r=insert(temp->r,data);
    return(temp);
  }
  else
   temp->l=insert(temp->l,data);
  return(temp);
}

void reset(struct reply a)
{
  a.ele=NULL;
  a.pos=0;
  temp_reply.ele=NULL;
  temp_reply.pos=0;
}

struct reply search(struct BSTnode *temp, int data)
{
    temp_reply.ele = temp;
    int num;
    temp_reply.pos++;
    if (temp!=NULL)
    num=temp->data;
    if(temp!=NULL)
    {
        return (data==num) ? temp_reply : data<num ? search(temp->l,data): search(temp->r,data);
    }
    else 
    {
        temp_reply.ele=NULL;
        return  temp_reply;
    }
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

//prints ascii tree for given Tree structure

int MIN(int a, int b)
{
  if(a>b)
  return b;
  else return a;
}

int MAX(int a, int b)
{
  if(a>b)
  return a;
  else return b;
}


void print_ascii_tree(struct BSTnode * t)
{
  struct asciinode_struct *proot;
  int xmin, i;
  if (t == NULL) return;
  proot = build_ascii_tree(t);
  compute_edge_lengths(proot);
  for (i=0; i < proot->height && i < MAX_HEIGHT; i++)
  {
    lprofile[i] = INFINITY;
  }
  compute_lprofile(proot, 0, 0);
  xmin = 0;
  for (i = 0; i < proot->height && i < MAX_HEIGHT; i++)
  {
    xmin = MIN(xmin, lprofile[i]);
  }
  for (i = 0; i< proot->height; i++)
  {
    print_next = 0;
    print_level(proot, -xmin, i);
    printf("\n");
  }
  if (proot->height >= MAX_HEIGHT)
  {
    printf("(This tree is taller than %d, and may be drawn incorrectly.)\n",
           MAX_HEIGHT);
  }
  free_ascii_tree(proot);
}

void print_level(struct asciinode_struct *node, int x, int level)
{
  int i, isleft;
  if (node == NULL) return;
  isleft = (node->parent_dir == -1);
  if (level == 0) 
  {
    for (i=0; i<(x-print_next-((node->lablen-isleft)/2)); i++) 
    {
      printf(" ");
    }
    print_next += i;
    printf("%s", node->label);
    print_next += node->lablen;
  } 
  else if (node->edge_length >= level) 
  {
    if (node->left != NULL) 
    {
      for (i=0; i<(x-print_next-(level)); i++) 
      {
        printf(" ");
      }
      print_next += i;
      printf("/");
      print_next++;
    }
    if (node->right != NULL) 
    {
      for (i=0; i<(x-print_next+(level)); i++) 
      {
        printf(" ");
      }
      print_next += i;
      printf("\\");
      print_next++;
    }
  } 
  else 
  {
    print_level(node->left, 
                x-node->edge_length-1, 
                level-node->edge_length-1);
    print_level(node->right, 
                x+node->edge_length+1, 
                level-node->edge_length-1);
  }
}


void compute_edge_lengths(struct asciinode_struct *node)
{
int h, hmin, i, delta;
if (node == NULL) return;
compute_edge_lengths(node->left);
compute_edge_lengths(node->right);

/* first fill in the edge_length of node */
if (node->right == NULL && node->left == NULL) 
{
  node->edge_length = 0;
} 
else 
{
  if (node->left != NULL) 
  {
    for (i=0; i<node->left->height && i < MAX_HEIGHT; i++) 
    {
      rprofile[i] = -INFINITY;
    }
    compute_rprofile(node->left, 0, 0);
    hmin = node->left->height;
  } 
  else 
  {
    hmin = 0;
  }
  if (node->right != NULL) 
  {
    for (i=0; i<node->right->height && i < MAX_HEIGHT; i++) 
    {
      lprofile[i] = INFINITY;
    }
    compute_lprofile(node->right, 0, 0);
    hmin = MIN(node->right->height, hmin);
  } 
  else 
  {
    hmin = 0;
  }
  delta = 4;
  for (i=0; i<hmin; i++) 
  {
    delta = MAX(delta, gap + 1 + rprofile[i] - lprofile[i]);
  }

  //If the node has two children of height 1, then we allow the
  //two leaves to be within 1, instead of 2 
  if (((node->left != NULL && node->left->height == 1) ||
        (node->right != NULL && node->right->height == 1))&&delta>4) 
  {
    delta--;
  }

  node->edge_length = ((delta+1)/2) - 1;
}

//now fill in the height of node
h = 1;
if (node->left != NULL) 
{
  h = MAX(node->left->height + node->edge_length + 1, h);
}
if (node->right != NULL) 
{
  h = MAX(node->right->height + node->edge_length + 1, h);
}
node->height = h;
}


struct asciinode_struct * build_ascii_tree_recursive(struct BSTnode * t)
{
  struct asciinode_struct * node;

  if (t == NULL) return NULL;

  node = malloc(sizeof(struct asciinode_struct));
  node->left = build_ascii_tree_recursive(t->l);
  node->right = build_ascii_tree_recursive(t->r);

  if (node->left != NULL)
  {
    node->left->parent_dir = -1;
  }

  if (node->right != NULL)
  {
    node->right->parent_dir = 1;
  }

  sprintf(node->label, "%d", t->data);
  node->lablen = strlen(node->label);

  return node;
}

//Copy the tree into the ascii node structre
struct asciinode_struct * build_ascii_tree(struct BSTnode * t)
{
  struct asciinode_struct *node;
  if (t == NULL) return NULL;
  node = build_ascii_tree_recursive(t);
  node->parent_dir = 0;
  return node;
}

//Free all the nodes of the given tree
void free_ascii_tree(struct asciinode_struct *node)
{
  if (node == NULL) return;
  free_ascii_tree(node->left);
  free_ascii_tree(node->right);
  free(node);
}

//The following function fills in the lprofile array for the given tree.
//It assumes that the center of the label of the root of this tree
//is located at a position (x,y).  It assumes that the edge_length
//fields have been computed for this tree.
void compute_lprofile(struct asciinode_struct *node, int x, int y)
{
  int i, isleft;
  if (node == NULL) return;
  isleft = (node->parent_dir == -1);
  lprofile[y] = MIN(lprofile[y], x-((node->lablen-isleft)/2));
  if (node->left != NULL) 
      {
        for (i=1; i <= node->edge_length && y+i < MAX_HEIGHT; i++) 
        {
          lprofile[y+i] = MIN(lprofile[y+i], x-i);
        }
      }
  compute_lprofile(node->left, x-node->edge_length-1, y+node->edge_length+1);
  compute_lprofile(node->right, x+node->edge_length+1, y+node->edge_length+1);
}

void compute_rprofile(struct asciinode_struct *node, int x, int y)
{
      int i, notleft;
      if (node == NULL) return;
      notleft = (node->parent_dir != -1);
      rprofile[y] = MAX(rprofile[y], x+((node->lablen-notleft)/2));
      if (node->right != NULL) 
      {
        for (i=1; i <= node->edge_length && y+i < MAX_HEIGHT; i++) 
        {
          rprofile[y+i] = MAX(rprofile[y+i], x+i);
        }
      }
      compute_rprofile(node->left, x-node->edge_length-1, y+node->edge_length+1);
      compute_rprofile(node->right, x+node->edge_length+1, y+node->edge_length+1);
}