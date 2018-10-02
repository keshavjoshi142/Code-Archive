int * initDS(int n)
{
    int *arr =  new int[n];
    for(int i=0 ; i<n ; i++)
        arr[i] = i;
    
    return arr;
}

int findParent(int n , int *arr)
{
    if(arr[n] == n)
        return n;
    else
        return findParent(arr[n] , arr);
}

void unionDS(int u , int v, int* arr)
{
    int U = findParent(u , arr);
    int V = findParent(v , arr);
    
    arr[U] = V;
}

void printP(int * arr, int n)
{
    for(int i=0 ; i<n ;i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;
}


int Solution::solve(int A, vector<vector<int> > &B) {
    
    priority_queue< pair < int , pair < int , int > > > pq;// priority based on first number..

    for(int i=0 ; i<B.size() ; i++)
    {
      pair < int , int > p = make_pair(B[i][0], B[i][1]);
      pq.push(make_pair(-1*B[i][2] , p));// priority queue orders in decending order that's negate the value///
    }

    int *arr = initDS(A+1);// A+1 is important
    
    int MSTcost = 0;
    
    while(!pq.empty())
    {
        pair< int , pair < int , int > > l = pq.top();
        pq.pop();
        if(findParent(l.second.first , arr) != findParent(l.second.second , arr))
        {
            unionDS(l.second.first , l.second.second , arr);
            MSTcost = MSTcost - l.first;
        }
        
    }
    
    return MSTcost;
    
}
