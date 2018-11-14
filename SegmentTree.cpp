#include <bits/stdc++.h>

using namespace std;


int tree[50];
int A[4] = {3,2,1,4};

void build(int n , int start , int end)
{

	if(start > end)return;

	if(start == end)
	{
		tree[n] = A[start]; 
		return;		
	}

	
	int mid = (start + end)/2;

	build(2*n+1 , start , mid);
	build(2*n+2 ,mid+1 , end);

	tree[n] = tree[2*n+1] + tree[2*n+2];

}

void update(int n ,int start , int end , int val ,int idx)
{
	if(start == end && start == idx)
	{
	cout<<"wjsh";
		tree[n] = val;
		A[idx] = val;
		return;
	}

	int mid = (start + end)/2;

	if(idx <= mid)update(2*n+1, start , mid , val , idx);
	else update(2*n+2 , mid+1 , end ,val ,idx);

	tree[n] = tree[2*n+1] + tree[2*n+2];

}



int main()
{

	build(0 , 0 , 3);


	

	update(0 , 0 , 3, 5 , 2);

	for(int i=0;i<7;i++)
	{
		cout<<tree[i]<<endl;
	}


}