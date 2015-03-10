/*
ID:haoziyi1
PROG:money
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
ifstream fin("money.in");
ofstream fout("money.out");
int V,N;
int c[25];
int main(){
    fin>>V>>N;
    for(int i=0;i<V;i++)
        fin>>c[i];
    sort(c,c+V);
    //dp[i][j]=dp[i-c[j]][j]+dp[i][j-1];
    int maxn=c[V-1]+1;
    vector<vector<long long> > dp(maxn,vector<long long>(25,0));
    for(int i=0;i<V;i++)
        dp[0][i]=1;
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<V;j++)
        {
            dp[i%maxn][j]=0;
            if(j>0)
                dp[i%maxn][j]+=dp[i%maxn][j-1];
            if(i>=c[j])
            {
                dp[i%maxn][j]+=dp[(i-c[j])%maxn][j];
            }
        }
    }
    fout<<dp[N%maxn][V-1]<<endl;

}

