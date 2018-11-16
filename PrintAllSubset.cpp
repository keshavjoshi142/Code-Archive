#include <bits/stdc++.h> 

using namespace std;

void printall(vector < string > & chosen)
{
	for(int i=0 ; i<chosen.size() ; i++)
	{
		cout << chosen[i] << " ";
	}
}


void subset(vector < string > & A , vector < string > &chosen)
{
	if(A.size() == 0)
	{
		printall(chosen);
		cout << endl;
	}
	else
	{
		string temp = A[0];

		A.erase(A.begin());
		subset(A , chosen);

		chosen.push_back(temp);

		subset(A , chosen);

		A.insert(A.begin() , temp);
		chosen.pop_back();
	}
}

int main()
{
	//string [] A = {"keshav" , "joshi" , "john" , "daisy"};
	vector < string > A{"keshav" , "joshi" , "john" , "daisy"};

	vector < string > chosen;
	subset(A , chosen);
}