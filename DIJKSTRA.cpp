#include<bits/stdc++.h>

using namespace std;


typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void addEdge(int u,int v,int w,std::vector<vii> &adj)
{
  adj[u].push_back(ii(v,w));
}

void dijkstra(std::vector<vii> &adj)
{
  vi dist(4,INT_MAX);
  dist[0]=0;

  priority_queue< ii , std::vector<ii> , greater<ii> > pq;

  pq.push(ii(0,0));

  while(!pq.empty())
  {
              ii front=pq.top();
              pq.pop();

              int d=front.first;
              int u=front.second;

              if(d > dist[u])continue;

              for(int j=0;j<(int)adj[u].size();j++)
              {
                ii v=adj[u][j];

                if(dist[u] + v.second < dist[v.first])
                {
                  dist[v.first]=dist[u]  +  v.second;
                  pq.push(ii(dist[v.first], v.first));
                }
              }
  }

  for(int i=0;i<4;i++)
  {
    cout<<"from "<<0<<"to "<<i<<" "<<dist[i];
    cout<<endl;
  }
}

int main()
{
  int V,E,s,u,v,w;
  std::vector<vii> adj;

  adj.assign(4,vii());


  cout<<"kl"<<endl;
  addEdge(0,1,2,adj);
  addEdge(0,2,2,adj);
  addEdge(1,2,3,adj);
  addEdge(2,0,4,adj);
  addEdge(2,3,2,adj);
  addEdge(3,3,1,adj);
  /*adj[0].push_back(ii(1,2));
  adj[0].push_back(ii(2,2));
  adj[1].push_back(ii(2,3));
  adj[2].push_back(ii(0,4));
  adj[2].push_back(ii(3,2));
  adj[3].push_back(ii(3,1));
  */

  dijkstra(adj);

}
