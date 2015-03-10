/*
ID:haoziyi1
PROG:stamps
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<cstring>
using namespace std;
ifstream fin("stamps.in");
ofstream fout("stamps.out");
//for f(i,j) means that for number i, at most j stamp can form or not.
// os f(i,j)=sum{f(i-k,j-1),k=1..i}
// f(0,0)=1
//f(i,0)=0;
//f(0,i)=1.
//for f(i) means for number i ,the minimum stamp to form i.
//then f(i)=min(f(i-st[k])=1);
int st[50];
int dp[10000+5]={0};
int main(){
    int k,n;
    fin>>k>>n;
    for(int i=0;i<n;i++)
        fin>>st[i];
    int mxn=10005;
    dp[0]=0;
   for(int j=1;;j++){
       dp[j%mxn]=j;
       for(int i=0;i<n;i++)
       {
          if(st[i]<=j&&dp[j%mxn]>dp[(j-st[i])%mxn]+1)
              dp[j%mxn]=dp[(j-st[i])%mxn]+1;
       }
     if(dp[j%mxn]>k)
     {
         fout<<j-1<<endl;
         break;
     }
    }
    //we have done.

}

