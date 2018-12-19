#include <bits/stdc++.h>

using namespace std;

#define MAX 1000
#define ll long long

int dp[MAX][MAX];


ll LIS(ll n , ll arr[])
{
	if(n == 0)
	{	
		dp[n] = 1;
	}

	if(dp[n] == -1)
	{
		ll max = 1;

		for(int i=0 ; i < n ;i++)
		{	
			int val = LIS(i , arr);
			if(arr[i] < arr[n] && val+1 >= max)
			{
				max = val + 1;
			}
		}

		dp[n] = max;

		
	}

	return dp[n];
}

int ZigZag(ll n , ll arr[])
{
	if(n == 0)
	{
		dp[n] = 1;
	}

	if(dp[n] == -1)
	{
		ll max = 1;

		for(int i=0 ; i < n ; i++)
		{
			int val = LIS(i , arr);

			if(val&1)
				{	
				if(arr[i] > arr[n] && val + 1 >= max)
					max = val + 1;
			}
			else
			{
				if(arr[i] < arr[n] && val + 1 >= max)
					max = val + 1;
			}
		}

		dp[n] = max;
	}

	return dp[n];
}


int smallestsum(int sum , int j , int  arr[])
{
	
	if(sum == 0 && j == -1)
		return 0;
	if(sum > 0 && j ==-1)
		return INT_MAX;

	if(dp[sum][j] == -1)
	{	
		
		dp[sum][j] = smallestsum(sum , j-1 , arr);		
		cout<<dp[sum][j]<<endl;
		if(sum >= arr[j])
			dp[sum][j] = min(dp[sum][j] , 1 + smallestsum(sum - arr[j] , j , arr));

	}

	return dp[sum][j];
}

int main()
{

	int arr[] = {10 , 2};
	memset(dp , -1, sizeof(dp));

	cout << smallestsum(20 , 1 , arr)<<endl;

	/*for(int i=0 ; i<100 ;i++)
	{
		for(int j=0 ; j<10 ; j++)
		{
			cout<<dp[i][j]<<" ";
		}

		cout<<endl;
	}*/

/*	int max = INT_MIN;
	for(int i=0 ;i<8 ;i++)
	{
		if(dp[i] > max)
			max = dp[i];
	
	}*/

	//cout<<max<<endl;
}



