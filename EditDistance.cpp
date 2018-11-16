#include<bits/stdc++.h>

#define ll long long
using namespace std;

int dp[5000][5000];

int edit_distance(string A , string B , int n , int m)
{

	if(n == 0)
		return m;
	if(m == 0)
		return n;

	if(dp[n][m] == -1)
	{	

		if(A[n-1] == B[m-1])
			dp[n][m] = edit_distance(A , B , n-1, m-1);
		else
		{
			int a = edit_distance(A , B , n-1, m-1) + 1;//replace 
			int b = edit_distance(A , B , n-1, m) + 1;//remove
			int c = edit_distance(A , B , n, m-1) + 1;//insert

			dp[n][m] = min(a , min(b , c));
		}
	}

	return dp[n][m];


}


int main()
{
	string A = "aac";
	string B = "abac";

	memset(dp , -1 , sizeof(dp));

	cout << edit_distance(A , B , A.length() , B.length()) << endl;
}