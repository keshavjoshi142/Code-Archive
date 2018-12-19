#include <bits/stdc++.h>

using namespace std;


int main()
{	
	int n;
	cin >> n;

	vector < int > v(n);

	for(int i=0 ; i < n ; i++)
	{
		cin >> v[i];
	}

	stack < int > s;

	int max_area = 0;
	int top;
	int area_with_top;

	int i = 0;

	while(i < n)
	{
		if(s.empty() || v[s.top()] <= v[i])
		{
			s.push(i);
			i++;
		}
		else
		{
			top = s.top();
			s.pop();

			area_with_top = v[top]*(s.empty() ? i : i - s.top()- 1);

			if(max_area < area_with_top)
				max_area = area_with_top;
		}
	}

	while(!s.empty())
	{
		top = s.top();
		s.pop();

		area_with_top = v[top]*(s.empty() ? i : i - s.top()- 1);

		if(max_area < area_with_top)
				max_area = area_with_top;
	}

	cout << max_area << endl;
}