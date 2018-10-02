#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int , int> ii;
#define ll long long
#define inf 2000000000
#define mod 1000000007
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<pp>
#define pb push_back
#define st set<int>
#define mst multiset<int>
//#define mp map<ll,int>
#define pr(cn,x) ((cn).find(x)!=(cn).end()) 
//#define tr(cn,it) for(typeof((cn).begin()) it=(cn).begin();it!=(cn).end();it++)
#define all(c) c.begin(), c.end()
#define sz(a) int((a).size())
#define for1(i,n) for(i=0;i<n;i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())

#define ll long long
#define pii pair<int,int>
#define BASE 31
#define MAX 1000000


const int N = 10000000;
int *lp = new int[N+1];
int *phi = new int[N + 1];
vector<int> pr;
int * isprime = new int[MAX+1];

ll binomialCoeff(int n , int r)
{
	if(r > n/2)
		r = n - r;

	ll ans = 1;

	for(int i=0;i<r;i++)
	{
		ans = ans*n;
		n--;

		ans = ans/(i+1);
	}

	return ans;
}

ll newBF(int n , int r)
{
	if(r > n/2)
		r = n-r;

	ll ans = 1;

	for(int i=0;i<r;i++)
	{
		ans = ans*pow(n , n);
		n--;

		ans = ans/pow(i+1 , i+1);
	}

	return ans;
}

int EulerTotient(int n)
{
	float ans = n;

	int p = 2;

	for(p ; p*p <= n;p++)
	{
			if(n%p == 0)
			{
				ans = ans*(1.0 - 1.0/(float)(p));

				while(n%p == 0)///////////removing all occurence of p in the prime fectorisation of n//////////////
					n = n/p;
			}
	}

	if(n > 1)////////////////////////???????????????//////////////////
	{
		ans = ans*(1.0 - 1.0/(float)(n));
	}

	return ans;
}


void prime_sieve(int N)///////////////////////////////////////give number of prime before N-----O(n*logn)/////////////////
{
	

	for(int i=0;i<=N;i++)
		isprime[i] = 1;


	for(int p=2 ; p*p <= N+1 ; p++)
	{
		if(isprime[p] == 1)
		{
			for(int i = 2*p ; i <= N ; i = i+p)
				isprime[i] = 0;
		}
	}

	

}


ll sumDivisor_Sieve(int N)///////////////////////////sum of all divisor of number from 1 to N------------O(n*logn)//////////////////////
					/////////////////////////////////usefull for large number of queries//////////////////
{
	int * count = new int[N+1];

	for(int i=1 ;i<=N;i++)
	{
		for(int j=i ;j<=N;j = j+i)
		{
			if(j%i == 0)
				count[i]++;
		}
	}

	ll ans = 0;

	for(int i=1;i<=N;i++)
	{
		ans = ans + i*count[i];
	}

	return ans;

}

ll divisorSum(int n)///////////////////////////////////////sum of all divisor of number from 1 to N-------O(N)///////////////////////////
{
    ll sum = 0;

    for (int i = 1; i <= n; ++i) 
        sum += (n / i) * i;


    return sum;
}

/*Let n = 6,
=> F(1) + F(2) + F(3) + F(4) + F(5) + F(6)
=> 1 will occurs 6 times in F(1), F(2),
   F(3), F(4), F(5) and F(6)
=> 2 will occurs 3 times in F(2), F(4) and
   F(6)
=> 3 will occur 2 times in F(3) and F(6)
=> 4 will occur 1 times in F(4)
=> 5 will occur 1 times in F(5)
=> 6 will occur 1 times in F(6)
*/



int isprime(int N)
{	
	if(N <= 1)
		return 0;
	if(N == 2)
		return 1;

	for(int i = 2 ; i*i <= N ;i++)
	{
		if(N%i == 0)
			return 0;
	}

	return 1;
}



ll* EulerTotient_Sieve(int N)///////////////////////////////////EulerTotient of all number from 1 to N/////////////////////
{
	ll * phi = new ll[N+1];////////this array contain the euler totient of N all N numbers//////////////////

	for(int i=1;i<=N;i++)
		phi[i] = i;

	prime_sieve(N);			//////////////using prime seive to reduce the time complexity to O(nlogn)/////////////////

	for(int k = 2 ; k<=N ;k++)
	{
		
		if(isprime[k] == 1)
		{	
			for(int p = k ;p <= N ;p = p+k)
			{
				phi[p] = phi[p] - phi[p]/k;
				
			}
		}
	}

	return phi;
}

ll * gcdSummation(int N)/////////////////////////summation of all pair of numbers from 1 to N////////////////
{
	ll* arr = EulerTotient_Sieve(MAX);

	
	ll * gcd = new ll[MAX];

	for(int i=0;i<=MAX;i++)
		gcd[i] = 0;
	

	for (int i=1; i<=MAX; ++i)
    	{
        // Iterate throght all the divisors
        // of i.
        	for (int j=2; i*j<=MAX; ++j)
            		gcd[i*j] += i*arr[j];
   	}

   	 for(int i=2 ; i<=MAX ;i++)
		gcd[i] = gcd[i] + gcd[i-1];


	return gcd;
}

int main()
{	
	int N;

	cin >> N;
	
	while(N!=0)
	{
		
		cout<<gcd[N]<<endl;
		cin >> N;

	}

	return 0;
}




