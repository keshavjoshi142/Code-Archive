#include <bits/stdc++.h>

using namespace std;

vector < int >  A;

int dp[1000][1000];

int func( int i, int sum)
{

	if(sum == 0)
		return 1;
	
	if(i < 0 && sum > 0)
		return 0;


	if(dp[i][sum] == -1)
	{	
		int a = 0;

		a += func(i-1 , sum);

		if(sum >= A[i])
			a += func(i , sum - A[i]);

		dp[i][sum] = a;
	}

	return dp[i][sum];
}




int main()
{
	int N;
	cin >> N;
	memset(dp , -1 , sizeof(dp));

	for(int i=0 ; i<N ; i++)
	{	
		int p;
		cin >> p;
		A.push_back(p);
	}

	int sum;
	cin >> sum;

	cout << func(A.size()-1 , sum) << endl;

	for(int i=0 ; i<A.size(); i++)
	{
		for(int j =0 ; j<=sum ; j++)
		{
			cout << dp[i][j] << " ";
		}

		cout << endl;
	}

}