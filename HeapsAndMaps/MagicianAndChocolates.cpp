#include <bits/stdc++.h>
#define  mod 1000000007

using namespace std;


int main()
{
	int K , N;
	cin >>  K >> N;

	vector < int > v(N);

	for(int i=0 ; i < N ; i++)
		cin >> v[i];

	priority_queue < int > pq;

	for(int i=0 ; i < N ; i++)
	{
		pq.push(v[i]);
	}

	int ans = 0;

	while(K--)
	{
		int C = pq.top();
		pq.pop();

		ans = (ans + C)%mod;

		pq.push(C/2);
	}

	cout << ans << endl;
}