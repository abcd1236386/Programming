/*
ID:haoziyi1
PROG:kimbits
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
ifstream fin("kimbits.in");
ofstream fout("kimbits.out");
long long C[32][32];
void dfs(int n,int l,long long i)
{
    if(n==1)
    {
        if(i==1)
            fout<<0;
        else
            fout<<1;
        return ;
    }
    //we check the higest bit to zero or one.
    //if highest is 0, we have C(n-1,l)+C(n-1,l-1)+..C(n-1,0).
    if(i<=C[n-1][l]){//
        fout<<0;
        dfs(n-1,l,i);
    }
    else{
        fout<<1;
        dfs(n-1,l-1,i-C[n-1][l]);
    }
}
int main(){
    for(int i=1;i<32;i++)
    {
        C[i][0]=1;
        long long c=1;
        for(int j=1;j<32;j++)
        {
            if(j>i){
                C[i][j]=C[i][i];
                continue;
            }
            c=c*(i-j+1)/j;
            C[i][j]=C[i][j-1]+c;
        }
    }
    int N,L;
    long long I;
    fin>>N>>L>>I;
    dfs(N,L,I);
    fout<<endl;
}

