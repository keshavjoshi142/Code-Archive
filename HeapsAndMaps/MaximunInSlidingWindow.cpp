#include <bits/stdc++.h>

using namespace std;


int main()
{
	int n;
	cin >> n;

	int k;

	cin >> k;

	vector < int > v(n);

	for(int i=0 ; i < n ; i++)
		cin >> v[i];

	deque < int > dq;
	vector < int > res;
	for(int i=0 ; i < n ; i++)
	{
		cout << v[i] << " ";
	}

	cout << endl;

	for(int i=0 ; i < n ; i++)
	{
		if(!dq.empty() && dq.front() == i - k)
			dq.pop_front();

		while(!dq.empty() && v[dq.back()] < v[i])
			dq.pop_back();

		dq.push_back(i);

		if(i >= k - 1)
			res.push_back(v[dq.front()]);
	}

	for(int i = 0; i < res.size() ; i++)
		cout << res[i] << " ";

}