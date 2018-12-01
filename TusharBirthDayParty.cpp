#include <bits/stdc++.h>


using namespace std;

int dp[101][10001];


vector < int > price;
vector < int > weight;
vector < int > capacity;



int knapSack(int i , int W)
{
	
	if(i == 1 && W < weight[i])
		return 0;
	else if(i == 1 && W >= weight[i])
		return 1;
	if(W == 0)
		return 0;

	//cout << "kkk" << endl;

	if(dp[i][W] == -1)
	{	
		int a = 100001;
		int b = 100001;

		if(i > 0)
		{
			a  = knapSack(i-1 , W);

			if(W > 2*weight[i])
				b = knapSack(i-1 , W - 2*weight[i]);
		}
		//cout << a << endl;
		dp[i][W] = min(a , b+1);
	}

	return dp[i][W];
}


int main()
{

	memset(dp , -1 ,sizeof(dp));
	int ans = 0;

	int N;
	cin >> N;
	for(int i=0 ; i< N; i++)
	{
		int a;
		cin >> a;
		ans += a;
		weight.push_back(a);
	}

	//cout << ans << endl;
	
	cout << knapSack(weight.size()-1 , ans) << endl;

}	