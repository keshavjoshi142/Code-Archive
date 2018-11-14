
using namespace std;
#include <bits/stdc++.h>
struct node
{
  int data;
  struct node *left;
  struct node *  right;
  int height;
};



typedef struct node NODE;

NODE * newnode(int data)
{
  NODE * node =(NODE*)malloc(sizeof(NODE));
  node->data=data;
  node->left=NULL;
  node->right=NULL;
}


int height(NODE * node)
{
  if(node==NULL)return -1;
  else{
    return node->height;
  }
}

NODE * right_rotate(NODE * y)
{
  NODE * x=y->left;
  y->left=x->right;
  x->right=y;

  y->height=max(height(y->left),height(y->right))+1;
  x->height=max(height(x->left),height(x->right))+1;
}

NODE * left_rotate(NODE * y)
{

  cout<<"here2\n";
  NODE * x=y->right;
  y->right=x->left;
  x->left=y;
  y->height=max(height(y->left),height(y->right))+1;
  x->height=max(height(x->left),height(x->right))+1;
}

NODE * insert(NODE * node,int key)
{  if(node==NULL)
  {
     return newnode(key);
  }

  if(key < node->data)
  {
    node->left=insert(node->left,key);
  }
  else if(key > node->data)
  {
    node->right=insert(node->right,key);
  }
  else return node;
  node->height=max(height(node->left),height(node->right))+1;
  //cout<<node->left<<endl;

  if(height(node->left)>=2+height(node->right))
  {
    if(height(node->left->left) >= height(node->left->right))
    {
      return right_rotate(node);
    }
    else{
      node->left=left_rotate(node->left);
      return right_rotate(node);
    }
  }
  else if(height(node->right)>= 2+height(node->left))
  {
    if(node->left!=NULL)
    cout<<node->left->data<<endl;
    if(node->right!=NULL)
    cout<<node->right->data<<endl;
    if(height(node->right->right) >= height(node->right->left))
    {
      return left_rotate(node);
    }
    else{
      node->right=right_rotate(node->right);
      return left_rotate(node);
    }
  }

  return node;

}

void preOrder(NODE *root)
{
    if(root != NULL)
    {
        cout<< root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}


int main()
{
  NODE *root = NULL;
  /* Constructing tree given in the above figure */
  root = insert(root, 10);
  cout<<"here7\n";
  root = insert(root, 20);
  cout<<"here6\n";
  root = insert(root, 30);
  cout<<"here5\n";
  root = insert(root, 40);
  cout<<"here4\n";
  root = insert(root, 50);
  cout<<"here3\n";
  cout<<root->right->left->data<<endl;
  root = insert(root, 25);

  /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
  */

  printf("Preorder traversal of the constructed AVL"
         " tree is \n");
  preOrder(root);

  return 0;
}
