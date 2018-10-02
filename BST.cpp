#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int , int> ii;
#define ll long long
#define inf 2000000000
#define mod 1000000007
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<pp>
#define pb push_back
#define st set<int>
#define mst multiset<int>
//#define mp map<ll,int>
#define pr(cn,x) ((cn).find(x)!=(cn).end()) 
//#define tr(cn,it) for(typeof((cn).begin()) it=(cn).begin();it!=(cn).end();it++)
#define all(c) c.begin(), c.end()
#define sz(a) int((a).size())
#define for1(i,n) for(i=0;i<n;i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())

#define ll long long
#define pii pair<int,int>
#define BASE 31
#define MAX 2000000000

// for competitive programmming use set<> and map<> instead to use below operation because set and map are implemented in RB-Tree which is 
// balanced BST.



/*
operation supported 

1. insetion ---- logn
2. search   ---- logn
3. deletion ---- logn
4. rank queries ---- logn          //for this time complexity you have to consturct the node with "left_count" 
		----- n  (when predefined definitoin is given) by treversing tree inorder and keep the count of # of element visited till now.. 
*/

/*
Construction of Binary Tree
1. from inorder and preorder/postorder
2. form preorder (by keeping MIN and MAX possible every node)

*/





struct node 
{
	int val;
	struct node * left;
	struct node * right;
	int left_count;
};

typedef struct node * NODE;
	
NODE createNode(int data)
{
	 NODE node = (NODE)malloc(sizeof(struct node));
	 node->val = data;
	 node->left = NULL;
	 node->right = NULL;
	 node->left_count = 1;
	 return node;

}



NODE addBST(int data , NODE root)
{
	if(root == NULL)
	{
		root = createNode(data);
		return root;		
	}
	if(data <= root->val)	
	{
		root->left = addBST(data , root->left);
		root->left_count++;
	}
	else
		root->right = addBST(data , root->right);
	
	return root;
}

int searchBST(int data , NODE root)/////////////  return 1 on success otherwise 0 ////////////
{
	if(root == NULL)
		return 0;
	
	if(root->val == data)
		return 1;
	
	if(data > root->val)
		return searchBST(data , root->right);
	else 
		return searchBST(data , root->left);
}


NODE nextSuccessor(NODE root)/////////////////used for deletion in BST/////////////////////
{	
	if(root = NULL)
		return NULL;
	
	if(root->left == NULL)
		return root;
	
	return nextSuccessor(root->left);	

}


NODE deleteBST(int data , NODE root)///////////return updated root node after the deletion of node/////////
{
	if(root == NULL)
		return NULL;
		
	if(data > root->val)
		root->right = deleteBST(data , root->right);
	else if(data < root->val)
	{	
		root->left = deleteBST(data , root->left);
		root->left_count--;
	}
	else											//if root needs to be deleted then there are 3 cases possible////////
	{												//      1. if right subtree is null						
		if(root->left == NULL)						//  	2. if left subtree is null
		{											//      3. if both  not null then we have to find next larger element from the right subtree and 
			NODE temp = root->right;				//         copy the content(i.e val) to the root node and then delete the copied node from the right
			free(root);								//		   subtree recursively.
			return temp;
		}
		if(root->right = NULL)
		{
			NODE temp = root->left;
			free(root);
			return temp;
		}
		else
		{
			NODE temp = nextSuccessor(root->right);
			
			root->val = temp->val;
			
			root->right = deleteBST(temp->val , root->right);
		
		}
	
		return root;
	}
	
	

} 

int kthsmallest(NODE root , int k)
{
	if(root == NULL)
		return 0;

	if(root->left_count == k)
		return root->val;

	if(k < root->left_count)
		kthsmallest(root->left , k);
	else
		kthsmallest(root->right , k - root->left_count);

}