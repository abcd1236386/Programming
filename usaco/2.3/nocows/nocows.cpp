/*
ID:haoziyi1
PROG:nocows
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
ifstream fin("nocows.in");
ofstream fout("nocows.out");
int cnt[200][100]={0};
int N,K;
int M=9901;
int main(){
    fin>>N>>K;
    // split to left and right subtree.
    //dp[i][j] is i node with depth less than or equal to j
    //dp[i][j]=sum(dp[k][j-1]*dp[i-1-k][j-1]) k is 1...i-2
    //so the result is dp[N][K]-dp[N][K-1];
    //dp[1][1]=1; 
    cnt[1][1]=1;
    for(int i=1;i<=K;i++)
        cnt[1][i]=1;
    for(int i=2;i<=N;i++)
        for(int j=2;j<=K;j++)
        {
            int s=0;
            for(int k=1;k<=i-2;k++)
            {
                s+=cnt[k][j-1]*cnt[i-1-k][j-1];
                s%=M;
            }
            cnt[i][j]=s;
        }
    fout<<(M+cnt[N][K]-cnt[N][K-1])%M<<endl;
}

