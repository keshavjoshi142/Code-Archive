#include <bits/stdc++.h>


using namespace std;

void nQueen(int n , vector < vector < int > >ans)
{
	if(n < 0)
		return;

	for(int i=0 ; i < n ; i++)
	{
		for(int j =0 ; j<ans.size() ; j++)
		{
			vector < int > v = ans[j];

			int k;

			for(k = 0  ; k < v.size() ; k++)
			{
				if(v[k] - i == n - k)
					break;
			}

			if( k == v.size() )
				ans.push_back(i);

		}
	}


}



int main()
{

}