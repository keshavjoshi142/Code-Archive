#include <bits/stdc++.h>

using namespace std;


int main()
{
	int N , K;
	cin >> N >> K;

	vector < int > A(N);

	for(int i=0 ; i < N ; i++)
		cin >> A[i];

	map < int  , int > m;

	vector < int > ans;


	for(int i=0 ; i < K ; i++)
		m[A[i]]++;

	ans.push_back(m.size());

	for(int i = K ; i < A.size() ; i++)
	{
		m[A[i]]++;
		m[A[i - K]]--;

		if(m[A[i - K]] == 0)
			m.erase(A[i - K]);


		ans.push_back(m.size());
	} 		 

	for(int i=0 ; i < ans.size() ; i++)
		cout << ans[i] << " ";


}