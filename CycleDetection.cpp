using namespace std;

#include <bits/stdc++.h>




void addEdges(int v,int w,list<int> *adj)
{
  adj[v].push_back(w);
}


void DFSVisit(int visitor[],list<int> *adj,int v,int rec_stack[],int &flag)
{
  visitor[v]=1;
  rec_stack[v]=1;
  cout<<v<<" ";
  for (std::list<int>::iterator it=adj[v].begin() ; it != adj[v].end(); ++it)
  {
    if(flag==1)break;

    if(rec_stack[*it]==1)
    {
      flag=1;
      break;
    }
    if(visitor[*it]==0)
    {
        DFSVisit(visitor,adj, *it,rec_stack,flag);
    }
  }

}

void DFS(list<int> *adj,int visitor[])
{
  int flag;

  for(int i=0;i<adj->size();i++)
  {
    int rec_stack[4]={0};

    flag=0;

    if(visitor[i]==0)
    {
      DFSVisit(visitor,adj,2,rec_stack,flag);
    }

    if(flag==1)break;
    
  }

  if(flag==1)cout<<"cycle";
  else cout<<"no cycle";
}


int main()
{
  list<int> adj[4];
  int visitor[4]={0};

  addEdges(0, 1, adj);
  addEdges(0, 2, adj);
  addEdges(1, 2, adj);
  addEdges(2, 0, adj);
  addEdges(2, 3, adj);
  addEdges(3, 3, adj);

  DFS(adj,visitor);


}
