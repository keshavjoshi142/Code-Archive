#include <bits/stdc++.h>

using namespace std;




int expmod(int a , int p , int mod)
{
	
	if(p == 0)
		return 1;

	cout << p << endl;
	
	if(p&1)
	{
		int p1 = a%mod;
		int q1 = expmod(a , p - 1 , mod)%mod;

		return (p1*q1)%mod;
	}
	else
	{
		int p1 = expmod(a , p/2 , mod)%mod;
		int q1 = expmod(a , p/2 , mod)%mod;

		return (p1*q1)%mod;
	}
}

int main()
{
	string A;

	cin >> A;

	int ans = 0;
	for(int i=0 ; i < A.length() ; i++)
	{
		if(A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u' || A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U')
		{
			ans = (ans + (A.length() - i)%10003)%10003;
		}
	}

	cout << ans << endl;

}