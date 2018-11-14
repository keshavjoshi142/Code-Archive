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
#define mp map<ll,int>
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


int N;
string s;

ll prefix[100];
ll suffix[100];






ll ppow(int i)
{	
	if(i==1 || i==0)
	return BASE;

	if(i&1)
	{
		i--;
		ll h = i/2;
		ll a = ppow(h)*ppow(h);

		return a*BASE;
	}
	else{
		ll h = i/2;

		return ppow(h)*ppow(h);
	}
}



ll * createPreffixHash()
{
	N = s.length();
	
	prefix[N];

	prefix[0] = s[0]%mod;
	
	for(int i=1;i<N;i++)
	{
		prefix[i] = (prefix[i-1]*ppow(1) + s[i]) % mod;///////////////////////////////(a%b + c)%b == (a+c)%b////////////////
		cout<<prefix[i]<<endl; 
	}

	return prefix;
}

ll * createSuffixHash()
{
	N = s.length();

	suffix[N];

	suffix[N-1] = s[N-1]%mod;

	for(int i = N -2 ;i >= 0 ;i--)
	{
		suffix[i] = (s[i] + suffix[i+1]*ppow(1)) % mod;
		cout<<suffix[i]<<endl;

	}

	return suffix;
}

bool isPallindrom(int L , int R)
{
	ll a = prefix[R] - prefix[L-1];
	a = a/ppow(L);

	ll b = suffix[L] - suffix[R+1];
	b = b/ppow(L);

	if(a == b)
		return 1;
	else 
		return 0;
}

ll NumPallindrom(int L , int R)
{

}

int main() {

	cin >> s;
	//cout<<ppow(1)<<endl;
	//cout<<ppow(2)<<endl;
	//cout<<ppow(3)<<endl;
	//cout<<ppow(4)<<endl;

	createPreffixHash();
	cout<<"kkk"<<endl;
		createSuffixHash();

	cout<<isPallindrom(0 , N-1);
	
}

	


