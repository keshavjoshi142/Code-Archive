#include <bits/stdc++.h>

using namespace std;

#define ll long long




/*int MCS(vector < int > & arr , int n)
{

	ll dp[n];

	for(int i=1 ; i<n ; i++)
	{
		dp[i] = max(dp[i-1] + arr[i] , arr[i]);
	}	

	return dp[n-1];

}
*/
/*int dp[100][100];

int edit_distance(string A , string B , int n , int m)
{

	if(n == 0)
		return m;
	if(m == 0)
		return n;

	if(dp[n][m] == -1)
	{	

		if(A[n-1] == B[m-1])
			dp[n][m] = edit_distance(A , B , n-1, m-1);
		else
		{
			int a = edit_distance(A , B , n-1, m-1) + 1;//replace 
			int b = edit_distance(A , B , n-1, m) + 1;//remove
			int c = edit_distance(A , B , n, m-1) + 1;//insert

			dp[n][m] = min(a , min(b , c));
		}
	}

	return dp[n][m];


}*/
/*
int dp1[100];

int partition_dif(int arr[] , int n ,int N)
{
	if(n == 0)
		return 0;

	if(dp1[n] == -1)
	{	
		int t = partition_dif(arr , n-1 , N);
		int a = abs(2*t - N);
		
		int min = INT_MAX;

		int index;

		for(int i=1 ; i< n ; i++)
		{
			int temp = abs(2*(partition_dif(arr , i , N) + arr[n-1]) -N);

			if(temp < min)
			{
				min = temp;
				index = i;
			}
		}

		int b = min;

		if(a < b)
			dp1[n] = t;
		else
			dp1[n] = partition_dif(arr , index , N) + arr[n-1];

		
	}

	return dp1[n];
}
*/
ll dp[1001][1001];

/*int sum_subset(int arr[] , int n , int T, int sum)
{
	if(T < sum)
		return 0;
	if(n == 0 && sum !=0)
		return 0;
	if(n==0 && sum == 0)
		return 1;
	if(n!=0 && sum ==0)
		return 1;
	
	if(dp[n][sum] == -1)
	{
		if(sum_subset(arr , n-1 , T - arr[n-1] ,sum))
			dp[n][sum] = 1;
		else if(sum >= arr[n-1] && sum_subset(arr , n-1 , T-arr[n-1] , sum - arr[n-1]))
			dp[n][sum] = 1;
		else
			dp[n][sum] = 0;		
	}

	return dp[n][sum];
}*/

/*int matrics(int arr[][3] , int i , int j , int N)
{	
	if(dp[i][j] == INT_MIN)
	{

		int up = INT_MIN, down = INT_MIN , right = INT_MIN , left = INT_MIN;

		if(i-1 >= 0 && arr[i-1][j] == arr[i][j] -1)
			up = matrics(arr , i-1 , j , N);
		else if(i+1 < N && arr[i+1][j] == arr[i][j] -1)
			down = matrics(arr , i+1 , j , N);
		else if(j-1 >= 0 && arr[i][j-1] == arr[i][j] -1)
			left = matrics(arr , i , j-1 , N);
		else if(j+1 < N && arr[i][j+1] == arr[i][j] -1)
			right = matrics(arr , i , j+1 , N);

		int max1 = max(up , down);
		int max2 = max(left ,right);
		int maxg = max(max1 , max2);

		if(maxg == INT_MIN)
			dp[i][j] = 1;
		else
			dp[i][j] = 1 + maxg;
		
	}

	return dp[i][j];

}
*/
int greedy = 0;

int optimal_game(int arr[] , int i , int j)
{
	if(abs(i - j) == 1)
		return max(arr[i] , arr[j]);
	if(dp[i][j] == -1)
	{	cout << "kesh" << endl;

		int a , b;
		if(arr[i+1] > arr[j])
		{	
			greedy = arr[i+1];
			a = arr[i] + optimal_game(arr , i+2 , j);
		}
		else
		{	
			greedy += arr[j];
			a = arr[i] + optimal_game(arr , i+1 , j-1);

		}	

		if(arr[j-1] > arr[i])
		{	
			greedy += arr[j-1];
			b = arr[j] + optimal_game(arr , i , j-2);
		}
		else
		{
			greedy += arr[i];
			b = arr[j] + optimal_game(arr , i+1 , j-1); 
		}	

		//cout<< i<<" "<<j<<" "<<a<<" "<< b << endl;
		dp[i][j] = max(a , b);
	}

	return dp[i][j];

}


void optimal_game_greedy(int arr[] , int i ,int j)
{
	cout << "kes"<<endl;
	if(abs(i-j) == 1)
	{ greedy += max(arr[i] , arr[j]);
		return;
	}
	//if(arr[i] > arr[j])
	{
		if(arr[i] > arr[j])
		{
			greedy += arr[i];

			if(arr[i+1] > arr[j])
				optimal_game_greedy(arr , i+2 , j);
			else
				optimal_game_greedy(arr , i+1 , j-1);
		}
		else
		{
			greedy += arr[j];
			if(arr[i] > arr[j-1])
				optimal_game_greedy(arr , i+1 , j-1);
			else
				optimal_game_greedy(arr , i , j-2);
		}	
	}

}

int knapsack(int price[] , int weight[] , int n , int W)
{
	if(n == 0)
		return 0;
	if(W == 0)
		return 0;

	if(dp[n][W] == -1)
	{
		int a = knapsack(price , weight , n-1 ,W);

		int b = 0;

		if(W >= weight[n-1])
		{
			b =  price[n-1] + knapsack(price , weight , n-1 , W - weight[n-1]);
		}

		dp[n][W] = max(a , b);
	}

	return dp[n][W];
}

int word_break(string word ,vector < string > & worddic , int i , int j)
{	
	string part;
	part = word.substr(i , j-i+1);
	if(i > j)
		return 0;

	for(int p=0 ; p < worddic.size() ; p++)
	{
		if(part.compare(worddic[p]) == 0)
			return 1;
	}

	if(dp[i][j] == -1)
	{	
		int flag = 0;
		for(int k = i ; k<j ;k++)
		{
			if(word_break(word ,worddic, i , k) && word_break(word ,worddic, k+1 , j))
			{
				flag = 1;
				break;
			}
		}

		if(flag == 1)
			dp[i][j] = 1;
		else
			dp[i][j] = 0;
	}

	return dp[i][j];

}


int dp1[1000][1000];

/*int rod_cutting(int n , int arr[])
{
	if(n == 0)
		return 0;

	if(dp1[n] == -1)
	{	
		int max  = INT_MIN;

		for(int i=1 ; i<= n ; i++)
		{
			int a = rod_cutting(n-i , arr) + arr[i-1];

			if(max < a)
				max = a;
		}

		dp1[n] = max;
	}

	return dp1[n];
}
*/
int dp2[1000];

int rod_product(int n)
{
	if(n==1)
		return 1;

	if(dp2[n] == -1)
	{	
		int max1 = INT_MIN;

		for(int i=1 ; i<n ; i++)
		{
			int a = rod_product(n-i)*i;
			if(a > max1)
				max1 = a;
		}

		dp2[n] = max(max1 , n);
	}
	
	return dp2[n];
}

int parenthesis(char symbol[] , char operators[] , int i ,int j, int opt)//opt = 0 means false and 1 means true
{
	if(i == j && opt == 0 && symbol[i] == 'F')
		return 1;
	if(i == j && opt == 1 && symbol[i] == 'T')
		return 1;
	if(i == j)
		return 0;

	if(opt == 1)
	{
		if(dp[i][j] == -1)
		{	
			int sum = 0;
			for(int k = i ; k <= j-1 ; k++)
			{
				if(operators[k] == '&')
				{
					sum += parenthesis(symbol , operators , i , k ,1)*parenthesis(symbol , operators , k+1 , j,1);
				}
				if(operators[k] == '|')
				{
					int Total = parenthesis(symbol , operators , i , k , 1) + parenthesis(symbol , operators , i , k , 0);
					int Total1 = parenthesis(symbol , operators , k+1 , j , 1) + parenthesis(symbol , operators , k+1 , j , 0);

					sum += Total1*Total -parenthesis(symbol , operators , i ,k , 0)*parenthesis(symbol , operators , k+1 , j ,0);
				}
				if(operators[k] == '^')
				{
					sum += parenthesis(symbol ,operators ,i , k ,1)*parenthesis(symbol , operators,k+1 , j,0)
							+ parenthesis(symbol , operators , i ,k ,0)*parenthesis(symbol , operators , k+1 ,j, 1);
				
				}
			}
			dp[i][j] = sum;

		}
	}
	if(opt == 0)
	{
		if(dp1[i][j] == -1)
		{	
			int sum = 0;
			for(int k = i ; k <= j-1 ; k++)
			{
				if(operators[k] == '&')
				{	
					int Total = parenthesis(symbol , operators , i , k , 1) + parenthesis(symbol , operators , i , k , 0);
					int Total1 = parenthesis(symbol , operators , k+1 , j , 1) + parenthesis(symbol , operators , k+1 , j , 0);

					sum += Total*Total1 - parenthesis(symbol , operators , i , k ,1)*parenthesis(symbol , operators , k+1 , j,1);
				}
				if(operators[k] == '|')
				{
					sum += parenthesis(symbol , operators , i ,k , 0)*parenthesis(symbol , operators , k+1 , j ,0);
				}
				if(operators[k] == '^')
				{
					sum += parenthesis(symbol ,operators ,i , k ,1)*parenthesis(symbol , operators,k+1 , j,1)
							+ parenthesis(symbol , operators , i ,k ,0)*parenthesis(symbol , operators , k+1 ,j, 0);
				
				}
			}

			dp1[i][j] = sum;
		}
	}

	if(opt == 1)
		return dp[i][j];
	else
		return dp1[i][j];

}

ll dice_problem(int n , int sum , int m)
{
	if(n==1 && sum <= m)
		return 1;
	else if(n==1 && sum > m)
		return 0;


	if(dp[n][sum] == -1)
	{	
		ll t = 0;
		for(int i=1 ; i<=m ; i++)
		{	
			if(sum > i)
				t += dice_problem(n-1 , sum - i , m);
		}

		dp[n][sum] = t;
	}

	return dp[n][sum];
}


int l[100];
int w[100];
int h[100];
int N;
int dp3[100][100][100];

int box_stack(int n ,int last_l , int last_w)
{


		//cout <<n<<" "<<last_l <<" " << last_w<< endl;		
	if(dp3[n][last_l][last_w] == -1)
	{
		
		int b = 0;
		//cout << N << endl;
		for(int i=0 ; i < N ; i++)
		{	
			int b1 = 0 , b2 = 0 , b3 = 0;
			if(h[i] < last_l && w[i] < last_w || h[i] < last_w && w[i] < last_l)
			{	
				//cout <<"n"<< n << endl;
				b1 = l[i] + box_stack(n+1 , h[i] ,w[i]);
			}
			if(h[i] < last_l && l[i] < last_w || h[i] < last_w && l[i] < last_l)
			{
				//cout <<"n"<< n << endl;
				b2 = w[i] + box_stack(n+1 , h[i] ,l[i]);

			}	
			if(l[i] < last_l && w[i] < last_w || l[i] < last_w && w[i] < last_l)
			{
				//cout <<"n"<< n << endl;
				b3 = h[i] + box_stack(n+1 , l[i] ,w[i]);
			}	

			int bg = max(b1 , max(b2 , b3));
			if(bg > b)
				b = bg;
		//cout <<b << endl;

		}

		dp3[n][last_l][last_w] = (b);
	}

	return dp3[n][last_l][last_w];
}


/*int main()
{	
	

    	memset(dp , -1 , sizeof(dp));
    	memset(dp1 , -1 , sizeof(dp1));
	
 	char symbol[] = "TTFT";
    	char operators[] = "|&^";

    	int n = 4;
	//cout << word_break(word , worddic , 0 , word.length()-1) << endl;
	cout << parenthesis(symbol , operators ,0 , n-1 ,1 )<<endl;

	for(int i=0 ; i<n ;i++)
    	{
    		for(int j=0 ; j<n;j++)
    		{
    			cout << dp[i][j] << " ";
    		}

    		cout << endl;
    	}
}
*/

/*int main()
{
	memset(dp2 , -1, sizeof(dp2));

	//cout << rod_product(10) << endl;

	int max = INT_MIN;

	int n = 8;

	for(int i=1 ; i< n ; i++)
	{
		int a = rod_product(n-i)*i;

		if(a > max)
			max = a;
	}

	cout << max <<  endl;
*/

int dp4[100][100];
int egg_dropping(int n , int k)
{
	if(k==1 || k==0)
		return k;

	if(n==1)
		return k;

	if(dp4[n][k] == -1)
	{	
		int min = INT_MAX;

		for(int i=1 ; i <=k ; i++)
		{
			int a = egg_dropping(n-1 , i-1);
			int b = egg_dropping(n , k-i);

			int max1 = max(a , b);
			if( max1  < min)
				min = max1;
		}

		dp4[n][k] = 1 + min;
	}

	return dp4[n][k];
}

/*int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		memset(dp3 , -1 , sizeof(dp3));
		

		cin >> N;

		for(int i=0 ; i<N ; i++)
		{
			cin >> h[i] >> w[i] >> l[i];
		}


		cout << box_stack(0 , 99 , 99 ) << endl;

	
	}


}*/

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n , k;
		cin >> n >> k;
		memset(dp4 , -1 , sizeof(dp4));

		cout << egg_dropping(n , k) << endl;
	}
}
/*int main()
{

    	int t;
    	cin >> t;

    	while(t--)
    	{	
		char symbol[100];
    		char operators[100];

    		memset(dp , -1 , sizeof(dp));
    		memset(dp1 , -1 , sizeof(dp1));

		string line;
    		vector <string> tokens;
    		

    		if(getline(cin ,line))
    		{
    			//cout << line << endl;
    			
    			while(line.length()== 0)
    				getline(cin , line);	
    			stringstream check1(line);
     
    			string intermediate;
     
    			while(getline(check1, intermediate, ' '))
    			{
        			tokens.push_back(intermediate);
    			}
    		}
		
		int p=0 , q=0;
    		for(int i=0 ; i< tokens.size() ;i++)
    		{	
    			//cout << tokens[i] << endl;
    			if(tokens[i].compare("T") == 0)
    			{
    				symbol[p] = 'T';
    				p++;
    			}
    			if(tokens[i].compare("F") == 0)
    			{
    				symbol[p] = 'F';
    				p++;
    			}
    			if(tokens[i].compare("and") == 0)
    			{
    				operators[q] = '&';
    				q++;
    			}
    			if(tokens[i].compare("or") == 0)
    			{
    				operators[q] = '|';
    				q++;
    			}
    			if(tokens[i].compare("xor") == 0)
    			{
    				operators[q] = '^';
    				q++;
    			}
    		}
    		
*/    		/*for(int i = 0 ; i< p ; i++)
    			cout << symbol[i];
    		cout << endl;

    		for(int j=0 ; j<q ; j++)
    			cout << operators[j];
*/
   /* 		cout << parenthesis(symbol , operators ,0 , p-1 ,1 )<< endl;	
    	}*/

    /*	

    	cout << parenthesis(symbol , operators ,0 , n-1 ,1 )<<endl;

    	for(int i=0 ; i<n ;i++)
    	{
    		for(int j=0 ; j<n;j++)
    		{
    			cout << dp[i][j] << " ";
    		}

    		cout << endl;
    	}*/



