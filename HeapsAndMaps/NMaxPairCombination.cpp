#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define mod 1000000007 
#define SIZE 100001



int main()
{	
	int n;
	cin >> n;

	vector < int > A(n);
	vector < int > B(n);

	for(int i=0 ; i<n ; i++)
		cin >> A[i];

	for(int i=0 ; i<n ; i++)
		cin >> B[i];

	sort(A.begin() , A.end());
	sort(B.begin() , B.end());

	priority_queue < pair < int , pair < int , int > > > pq;

	pair < int , int > p = make_pair(A.size() - 1 , B.size() - 1);

	int sum = A[A.size() - 1] + B[B.size() - 1];

	pq.push(make_pair(sum , p));

	int k = 0;

	set < pair < int , int > > s;

	vector < int > ans;

	while(k < n)
	{
		pair < int , pair < int , int > > p = pq.top();
		pq.pop();

		s.insert(p.second);
		ans.push_back(p.first);

		pair < int , int > p1 = make_pair(p.second.first - 1 , p.second.second);
		pair < int , int > p2 = make_pair(p.second.first , p.second.second - 1);

		if(s.find(p1) == s.end())
		{
			int sum1 = A[p.second.first - 1] + B[p.second.second];

			pq.push(make_pair(sum1 , p1));

			s.insert(p1);
		} 

		if(s.find(p2) == s.end())
		{
			int sum2 = A[p.second.first] + B[p.second.second-1];

			pq.push(make_pair(sum2 , p2));

			s.insert(p2);
		}

		k++;

	}

	for(int i=0 ; i < ans.size() ; i++)
		cout << ans[i] << " ";








}