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
#define MAX 2000000000


int dp[100][100];

set<string> dpset[1000][1000];

int LCS(string s1 , string s2 , int n , int m)
{
	if(n==0 || m==0)
	{
		dp[n][m] = 0;	
		
		return 0;
	}
	if(dp[n][m] == -1)
	{
		if(s1[n-1] == s2[m-1])
		{
			dp[n][m] = 1 + LCS(s1 , s2 , n-1 , m-1);
		}
		else
		{
			dp[n][m] = max(LCS(s1 , s2 , n-1 ,m) , LCS(s1 , s2 , n ,m-1));
		}

	}

	return dp[n][m];
}

string backtrack(string s1 , string s2 , int n , int m)
{
	if(n == 0 || m == 0)
		return "";
	
	if(s1[n-1] == s2[m-1])
	{
		string ans = backtrack(s1 , s2 , n-1 , m-1) + s1[n-1];
		return ans;
	}

	if(dp[n-1][m] > dp[n][m-1])
		return backtrack(s1 , s2 , n-1 , m);
	
	else
		return backtrack(s1 , s2 , n ,m-1);
	
}

set<string> backtrackAll(string s1 , string s2 , int n , int m)
{
	if(n==0 || m==0)
	{
		dpset[n][m] = {};
	}

	if(s1[n-1] == s2[m-1])
	{
		set<string> s = dpset[n-1][m-1];
		set<string> temp;
		for(set<string>::iterator itr=s.begin() ;itr!=s.end() ;++itr)
		{
			string str = *itr;
			str = str.append(1, s1[n-1]);
			temp.insert(str);
		}

		dpset[n][m] = temp;

		return temp;
	}

	if(dp[n-1][m] > dp[n][m-1])
	{
		dpset[n][m] = dpset[n-1][m];
	}
	else if(dp[n-1][m] < dp[n][m-1])
	{
		dpset[n][m] = dpset[n][m-1];
	}
	else
	{
		set<string> s1 =  dpset[n][m-1];
		set<string> s2 = dpset[n-1][m];

		//sort(s1.begin() , s1.end());
		//sort(s2.begin() , s2.end());

		int size = s1.size() + s2.size();
		set<string> temp;

		set<string> ans = set<string> (temp.begin() , set_union(all(s1) ,all(s2) , temp.begin()));

		dpset[n][m] = ans;
	}

	return dpset[n][m];

}


int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		string s1;
		string s2;

		cin >> s1;
		cin >> s2;

		memset(dp , -1 ,sizeof(dp));

		int lcs = LCS(s1 , s2 , s1.length() , s2.length());
		cout<<lcs<<endl;

		for(int i=0;i<=s1.length();i++)
		{
			for(int j=0;j<=s2.length();j++)
			{
				cout<<dp[i][j]<<"        ";
			}
			cout<<endl;
		} 
		cout<<backtrack(s1 , s2 , s1.length() , s2.length())<<endl;
	}	

	

}
	






