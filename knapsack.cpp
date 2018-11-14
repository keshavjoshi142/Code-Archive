#include<bits/stdc++.h>

using namespace std;

int main()
{
  int wt[]={10,20,30};
  int val[]={60,100,120};

  int W=50;

  int i ,j, dp[20][20];

  memset(dp, 0 ,sizeof dp);

  for(int i=0;i<=W;i++)
  {
    dp[0][i]=0;
  }

  for(int i=0;i<=3;i++)
  {
    dp[i][0]=0;
  }

  for(int i=1;i<=3;i++)
  {
              for(int j=1;j<=W;j++)
              {
                      if(wt[i-1] > W)
                      {
                        dp[i][j]=dp[i-1][j];
                      }
                      else{
                        dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
                      }
              }
  }

  cout<<dp[3][W];



}
