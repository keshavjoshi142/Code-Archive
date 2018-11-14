#include<bits/stdc++.h>

using namespace std;

#define INF 1000000000

int main()
{
  int T;
  cin>>T;
  while(T--)
  {
        int N,M,P;

        cin>>N>>M>>P;

      std::vector<std::vector<int> > v(N , std::vector<int>(N));


        int i,j;
        for( i=0;i<N;i++)
        {
              for(j=0;j<N;j++)
              {
                v[i][j]=INF;
              }
              v[i][i]=0;

        }

        for(int i=0;i<M;i++)
        {
          int a,b,w;
          cin>>a>>b>>w;
          a--;b--;
          v[a][b]=w;
          v[b][a]=w;
        }
        //cout<<"k"<<endl;


        for(int k=0;k<N;k++)
        {
          for(int i=0;i<N;i++)
          {
            for(int j=0;j<N;j++)
            {
              v[i][j]=min(v[i][j] , v[i][k]+v[k][j]);
              //cout<<v[i][j]<<endl;
            }

          }
        }


        int sum=0;


        for(int i=1;i<N;i++)
        {
          sum=sum+(N-1)*v[0][i];
          for(int j=0;j<N;j++)
          {
            //cout<<v[i][j]<<"                 ";
            sum+=v[i][j];
          }
          //cout<<endl;
        }

        double ans;
        double d=pow(N-1,P);

        ans=(double)sum/d;

        cout<<ans<<endl;


  }
}
