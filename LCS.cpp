#include<bits/stdc++.h>

using namespace std;


int dp[100][100];


int LCS(string A , string B , int n , int m)
{

	if(n < 0 || m < 0)
		return INT_MAX;

	if(dp[n][m] == -1)
	{
		if(A[n] == B[m])
			dp[n][m] = 1;
		else
			dp[n][m] = max(LCS(A , B , n-1 , m) , LCS(A , B , n , m-1));
	}
	

	return dp[n][m];


}



int main()
{
	string A;
	string B;

	cin >> A >> B;

	int n = A.size();
	int m = B.size();

	memset(dp , -1 , sizeof(dp));

	cout<<LCS(A , B , n-1 , m-1);


}