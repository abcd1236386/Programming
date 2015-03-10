/*
ID:haoziyi1
PROG:inflate
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
ifstream fin("inflate.in");
ofstream fout("inflate.out");
int dp[10005];
int v[10005];
int c[10005];
int main(){
    dp[0]=0;
    int m,n;
    fin>>m>>n;
    for(int i=0;i<n;i++)
        fin>>v[i+1]>>c[i+1];
    //dp[i][j]=max(dp[i-1][j],dp[i-1][j-c[i]]+v[i]);
    //dp[0][0]=0;
    //dp[0][i]=0;
    //dp[i][0]=0;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(j>=c[i]&&dp[j]<dp[j-c[i]]+v[i])
                dp[j]=dp[j-c[i]]+v[i];
        }
    }
    cout<<dp[m]<<endl;
    fout<<dp[m]<<endl;
}

