#include <bits/stdc++.h>

using namespace std;

int dp[10000];


string A;


int func(int i)
{	
	if(i == -1)
		return 1;

	if(i == 0)
	{
		if(A[i] == '0')
			return 0;
		else
			return 1;
	}
	

	if(dp[i] == -1)
	{	
		int a = 0 , b = 0;

		if(A[i] != '0')
			a = func(i-1);

		string s1 = A.substr(i-1 , 2);

		//cout << s1 << endl;		
		if(stoi(s1) > 0 && stoi(s1) < 27 && A[i-1] != '0')
			b = func(i-2);

		//cout << a << " " << b << endl;
		dp[i] = a + b; 
	}

	return dp[i];
}



int main()
{
	cin >> A;



	memset(dp , -1 , sizeof(dp));

	cout << func(A.size()-1) << endl;

	

}