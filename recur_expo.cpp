#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define matrics vector< vector < ll > > 

matrics matrics_multi(matrics A , matrics B , ll M)
{	
	matrics ans(A.size() , vector< ll >(B[0].size()));

	for(ll i =0 ; i < A.size() ; i++)
	{
		for(ll j=0 ; j < B[0].size() ; j++)
		{	
			ll sum = 0;

			for(ll k = 0 ; k < A[0].size() ; k++)
			{
				sum += A[i][k]*B[k][j];
			}

			ans[i][j] = sum%M;
		}
	}

	return ans;
}


matrics matrics_pow(matrics A , ll n , ll M)
{
	if( n==1 || n==0 )
		return A;

	if( n&1 )
		return matrics_multi(A , matrics_pow(A , n-1 ,M) , M);
	else
		return matrics_pow(matrics_multi(A , A , M) , n/2 , M);

}



int main()
{
	
	ll T1;
	
	scanf("%lld" , &T1);

	matrics T(2 , vector < ll > (2));

	T[0][0] = 0;
	T[0][1] = 1;
	T[1][0] = 1;
	T[1][1] = 1;

	matrics F1(2 , vector <ll > (1));

	F1[0][0] = 1;
	F1[1][0] = 1;
	
	while(T1--)
	{
		ll N , M;
		scanf("%lld" , &N);
		scanf("%lld" , &M);

		matrics T_pow = matrics_pow(T , N-1 ,M);
		matrics fib_ans = matrics_multi(T_pow , F1 , M);

		printf("%lld\n",2*fib_ans[0][0]%M); 
	}



}