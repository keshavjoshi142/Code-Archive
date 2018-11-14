#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

void addEdges(int v,int w,list<int> *adj)
{
  adj[v].push_back(w);
}

vi sta;

void DFS1(list <int> *adj, int *visitor, int v)
{
  visitor[v]=1;

  for(std::list<int>::iterator it=adj[v].begin() ; it != adj[v].end(); ++it)
  {
    if(visitor[*it]!=1)
    {
      DFS1(adj,visitor,*it);
    }
  }

  sta.push_back(v);
}


int main()
{
  list<int> adj[5];
  int visitor[5]={0};

  addEdges(0, 1, adj);
  addEdges(0, 2, adj);
  addEdges(1, 3, adj);
  //addEdges(2, 0, adj);
  addEdges(2, 3, adj);
  addEdges(3, 4, adj);

for(int i=0;i<5;i++)
{
  if(visitor[i]!=1)DFS1(adj,visitor,i);
}

for(int i=sta.size()-1;i>=0;i--)
{
  cout<<sta[i]<<" ";
}


}
