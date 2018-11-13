#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define SIZE 100000
typedef pair<int , int > ii;



int N;
int max1;

int LAP(int i , int j , vector < int > & A)
{
	if(j == N-1)
		return 2;

	if(dp[i][j] == -1)
	{
		for(int k = j+1 ; k < N ; k++)
		{
			if(2*A[j] == A[i] + A[k])
			{
				dp[i][j] = 1 + LAP(j , k , A);
				break;
			}
		}

		if(dp[i][j] == -1)	
			dp[i][j] = 2;
	}

	if(dp[i][j] > max1)
		max1 = dp[i][j];

	return dp[i][j];
}





int main() {

	memset(dp , -1 , sizeof(dp));

	max1 = INT_MIN;

	cin >> N;
	
	vector < int > A(N);

	for(int i=0 ; i < N ; i++)
	{
		cin >> A[i];
	}
	

	for(int i=0 ; i<N ; i++){
		for(int j = i+1 ; j< N ; j++){
			LAP(i , j , A);
		}
	}


	cout << max1 << endl;


}
