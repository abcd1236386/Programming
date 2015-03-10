/*
ID:haoziyi1
PROG:subset
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
ifstream fin("subset.in");
ofstream fout("subset.out");
int N;
int osm=0;
int nsm=0;
void findinset(int cur,int rem,int picked)
{
    if(rem==0){
        if(N%2==0&&picked==N/2)
            nsm++;
        else
            osm++;
        return ;
    }
    if(cur>N||rem<0||picked>=N/2)
        return ;
    for(int i=cur;i<=N;i++)
    {
        findinset(i+1,rem-i,picked+1);
    }
}
int iabs(int x)
{
    return x<0?-x:x;
}
long long finddp(int maxn)
{
    vector<long long> dp[2];
    dp[0].resize(maxn+1,0);
    dp[1].resize(maxn+1,0);
    dp[0][0]=1;
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<=maxn;j++)
        {
            if(j==0)
                dp[i%2][j]=dp[(i-1)%2][i+j];
            else{
                dp[i%2][j]=dp[(i-1)%2][i+j]+dp[(i-1)%2][iabs(i-j)];
                if(i==j)
                    dp[i%2][j]+=dp[(i-1)%2][0];
            }
        }
    }
    return dp[N%2][0];
}
int main(){
   
   while( fin>>N){
    int sm=(N*N+N)/2;
    if(sm&1)
        fout<<0<<endl;
    else
    {
       
        fout<<finddp(sm)/2<<endl;
    }
   }
}

