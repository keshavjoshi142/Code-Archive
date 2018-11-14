#include<bits/stdc++.h>

using namespace std;

typedef pair < int , int> ii;
typedef vector < int > vi;
typedef vector<ii> vii;

void addEdge(int u , int v, int w , std::vector<vii> &adj)
{
  adj[u].push_back(ii(v,w));
}


void bellman_ford(std::vector<vii> & adj  , int s)
{
  vi dist(4,INT_MAX);

  dist[s]=0;

  for(int i=0; i<4-1;i++ )
  {
        for(int u=0; u < V;u++)
        {
            for(int j=0;j < (int)adj[u].size();j++)
            {
              ii v=adj[u][j];
              dist[v.first]=min(dist[v.first] , dist[u]+v.second);
            }
        }
  }
}

int main()
{
    std::vector<vii> adj;

    adj.assign(4, vii());

    addEdge(0,1,2,adj);
    addEdge(0,2,2,adj);
    addEdge(1,2,3,adj);
    addEdge(2,0,4,adj);
    addEdge(2,3,2,adj);
    addEdge(3,3,1,adj);

    bellman_ford(adj , 0);
}
