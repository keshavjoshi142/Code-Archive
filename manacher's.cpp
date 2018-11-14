using namespace std;

#include <bits/stdc++.h>

int main()
{
  int T;
  cin>>T;

  while(T--)
  {
    string s;
    cin>>s;
    ///////////////////////////////------PREPROCESING OF STRING FOR MANACHER'S ALGORITHM---------/////////////////
    int length=s.length();
    char *str_arr=new char[2*length+3];

    str_arr[0]='$';
    int p=0;
    for(int i=1;i<2*length+2;i++)
    {
      str_arr[i]='#';
      i++;
      str_arr[i]=s[p];
      p++;
    }
    str_arr[2*length+2]='@';

    int *arr=new int[2*length+3];

    for(int i=0;i<2*length+3;i++)
    {
      arr[i]=0;
    }
   /////////////////////////////----MANACHER'S ALGORITHM-----------//////////////////////////////////////
    int C=0,R=0;



    for(int i=0;i<2*length+3;i++)
    {
      int mirr=2*C-i;

      if(i < R)
      {
        arr[i]=min(R-i , arr[mirr]);
      }

      while(str_arr[ i + (1 + arr[i])] == str_arr[i - ( 1+ arr[i])])
      {
        arr[i]++;
      }

      if(i+arr[i] > R)
      {
        C=i;
        R=i+arr[i];
      }
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
    int max=0;
    for(int i=0;i<2*length+3;i++)
    {
      if(arr[i] > max)
      {
        max=arr[i];
      }

    }

    if(max==1)cout<<"NO"<<endl;
    else if (max > 1) cout<<"YES"<<endl;



  }
}
