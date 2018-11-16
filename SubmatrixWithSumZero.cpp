#include <bits/stdc++.h>

using namespace std;


int solve(vector<vector <int> > &A) {
	int r = A.size();
	
	if(!r) return 0;
	
	int c = A[0].size();
	
	if(!c) return 0;

	vector<vector <int > > pre;

	pre.resize(r, vector<int>(c, 0));

	for(int i = 0; i < r; ++i) {
		
		for(int j = 0; j < c; ++j) {
			
			pre[i][j] = A[i][j];
			
			if(i) pre[i][j] += pre[i - 1][j];
			
			if(j) pre[i][j] += pre[i][j - 1];
			
			if(i && j) pre[i][j] -= pre[i - 1][j - 1];
			
			
		
		}

		cout << endl;
	}
	int ans = 0;
	
	for(int r1 = 0; r1 < r; ++r1) {
			
			for(int r2 = r1; r2 < r; ++r2) {

				unordered_map<int, int> count;
				count[0] = 1;
				
				for(int j = 0; j < c; ++j) {
					
					int val = pre[r2][j];
					
					if(r1) 
						val -= pre[r1 - 1][j];
					
				     
                    ans += count[val];
                    count[val]++;
                   
				}
		}
	}

	return ans;

}


int main()
{	
	int n , m;
	cin >> n >> m;
	vector<vector<int>> A;
	for(int i=0 ; i<n ; i++)
	{	
		vector < int > v(m);
		for (int j =0 ; j<m ; j++)
		{
			cin >> v[j]; 
			
		}

		A.push_back(v);
		
	}
	cout << solve(A) << endl;
}