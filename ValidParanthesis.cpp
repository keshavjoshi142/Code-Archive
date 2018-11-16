#include <bits/stdc++.h>

using namespace std;




string A;

int dp[100000];

int max1;

int func(int i)
{
	if(i <= 0)
		return 0;


	if(dp[i] == 0)
	{
		if(A[i] == ')')
		{
			if(A[i-1] == '(')
				dp[i] = 2 + func(i-2);
			else
			{
				//cout << A[i-1] << endl;
				int a = func(i-1);

				if(i -a -1 >= 0 && A[i - a -1] == '(')
				{
					dp[i] = 2 + func(i-1);

					if(i-a-2 >= 0)
						dp[i] += dp[i-a-2];
				}
				else
					dp[i] = 0;
			}
		}
		else
		{
			dp[i] = 0;
		}
		
	}

	/*if(dp[i] > max1)
		max1 = dp[i];*/

	return dp[i];
}





int main()
{
	cin >> A;

	

	max1 = INT_MIN;

	cout << A.size() << endl;
	//cout << func(A.size()-1) << endl;

	for(int i=0 ; i<A.size() ;i++)
	{	
		memset(dp , 0 , sizeof(dp));
		
		int a = func(i);

		cout << a << endl;

		max1 = max(max1 , a);
	}

	

	cout << max1 << endl;
}