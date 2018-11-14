#include<bits/stdc++.h>

using namespace std;




int dp[1000][1000];


int func(int i , int j , vector < int > & A)
{
	if(i == j)
		return A[i];

	if(i == j-1)
		return max(A[i] , A[j]);

	if(dp[i][j] == -1)
	{
		dp[i][j] = max(A[i] + min(func(i+2 , j , A) , func(i+1 , j-1 , A)) , A[j] + min(func(i , j-2, A) , func(i+1 , j-1,A)));
	}

	return dp[i][j];

}


int main()
{
	int N;
	cin >> N;

	memset(dp , -1 , sizeof(dp));

	vector < int > A(N);

	for(int i=0 ; i<N ; i++)
	{
		cin >> A[i];
	}

	cout << func(0 , N-1 , A) << endl;

}
