#include <bits/stdc++.h>

using namespace std;

int A[] = {3,2,1,4};


int n = 4;

int tree[10];




/////////////////////bottom up build/////////////////
void build()
{

	for(int i=0;i<n;i++)
	{
		tree[n+i] = A[i];
	}

	for(int i = n-1 ; i>0 ;i--)
	{
		tree[i] =  tree[2*i] + tree[2*i+1];
	}

}



///////////////bottom up updation/////////////////
void update(int val , int idx)
{
	tree[n+idx] = val;
	A[idx] = val;

	int i = (idx + n)/2;

	while(i>0)
	{
			tree[i] = tree[i*2] + tree[2*i+1];

			i/=2;
	} 
}




///////// buttom up finding ////////////////
int query(int l , int r)// query [l , r) including l but excluding r
{

	l = l + n;
	r = r + n;

	int ans = 0;

	while(l < r)
	{
		if(l&1)
		{
			ans = ans + tree[l];// l is odd then add to the answer....
			l++;
		}
		if(r&1)
		{
			r--;				// r is odd , do not add to the ans first decrease it....
			ans = ans + tree[r];
		}

		l = l/2;
		r = r/2;
	}

	return ans;


}






int main()
{

		build();

		update(5 , 2);

		for(int i=1;i<8;i++)
		{
			cout<<tree[i]<<endl;
		}

			cout<<query(1,3);
}