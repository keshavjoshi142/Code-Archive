#include <bits/stdc++.h>




using namespace std;

int dp[1000][1000];

vector < int > A;

int func(int l , int r)
{
	int Min = INT_MAX;

	int minC;

		if(dp[l][r] == -1)
		{	

			int flag  = 0;
			
			for(int i=0 ; i<A.size() ; i++)
			{

				int c = A[i];

				if(c > l && c < r)
				{	
					flag = 1; 
					int a = 0;
					a = func(l , c) + func(c , r);
					
					if(a < Min)
					{	
						Min = a;
						minC = c;
					}
				}

			}

			if(flag == 0)
				dp[l][r] = 0;						
			else
				dp[l][r] = Min + r - l;
		}

		return dp[l][r];

	}


	vector < int > backtrack(int l , int r)
	{

		int a = INT_MAX;
		int c;
		//cout << "lll" << endl;
		int flag = 0;
		vector < int > ans;
		for(int i=0 ; i<A.size() ; i++)
		{
			if(A[i] > l && A[i] < r)
			{	
				flag = 1;
				if(dp[l][A[i]] + dp[A[i]][r] < a)
				{
					a = dp[l][A[i]] + dp[A[i]][r];
					c = A[i];
				}
			}
		}

		if(flag == 1)
		{
			ans.push_back(c);

			vector < int > lVec = backtrack(l , c);
			vector < int > rVec = backtrack(c , r);

			for(int i=0 ; i < lVec.size() ;i++)
				ans.push_back(lVec[i]);

			for(int i=0 ; i < rVec.size() ;i++)
				ans.push_back(rVec[i]); 
	
			
			return ans;
		}
		else
			return ans;
			
	}


int main()
{
	int N;

	int n;

	int a = 48;
	cout << (char)a << endl;
	cin >> N >> n;

	for(int i=0 ; i<n ; i++)
	{	
		int a;
		cin >> a;
		A.push_back(a);
	} 

	//vector <int> ans;

	memset(dp , -1 ,sizeof(dp));


	cout << func(0 , N) << endl;

	cout << "kkk" << endl;

	vector < int > ans;
	ans = backtrack(0 , N);
	
	for(int i=0 ; i<ans.size() ; i++)
		cout << ans[i] << " ";

	cout << endl;
}
