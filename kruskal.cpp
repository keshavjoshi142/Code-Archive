#include<iostream>
#include<vector>
#include<algorithm>
#include "timer.h"
#include <bits/stdc++.h>

using namespace std;


int fathers[3000];

int find(int x){
    if(fathers[x] == x){
        return x;
    }
    return find(fathers[x]);
}

void unite(int x, int y){
    int fx = find(x);
    int fy = find(y);
    fathers[fx] = fy;
}


void kruskal(vector < pair < int , pair < int , int > > > &edges,int n ,int m)
{
  int mst_weight = 0, mst_edges = 0;
  int mst_ni = 0;
  int a,b,w;

  sort(edges.begin(),edges.end());

  while( ( mst_edges < n-1) || (mst_ni < m) ){

      a = edges[mst_ni].second.first;
      b = edges[mst_ni].second.second;
      w = edges[mst_ni].first;

      if( find(a) != find(b) ) {

          unite(a,b);

          mst_weight += w;


          mst_edges++;
      }

      mst_ni++;
  }

  cout<<mst_weight<<endl;
}


int main(){

    for(int i=0;i<3000;i++){
        fathers[i]=i;
    }

    int n,m;
    int a,b,w;
    vector < pair < int , pair < int , int > > > edges;

    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        edges.push_back(make_pair( w,make_pair(a,b) ) );
    }

	StartTimer();
    kruskal(edges,n,m);
	float f = GetTimer();
	printf("Time=%fs", f/1000);
}
