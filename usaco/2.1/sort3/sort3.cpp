/*
ID:haoziyi1
PROG:sort3
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
ifstream fin("sort3.in");
ofstream fout("sort3.out");
int num[1000];
int nst[1000];
int main(){
    int n;fin>>n;
    for(int i=0;i<n;i++){
        fin>>num[i];
        nst[i]=num[i];
    }
    sort(nst,nst+n);
    int cnt[4][4]={0};
    for(int i=0;i<n;i++)
        cnt[nst[i]][num[i]]++;
    int tc=0;
    int rm=0;
    for(int i=1;i<=3;i++)
    {
        for(int j=i+1;j<=3;j++)
        {
            int m=min(cnt[i][j],cnt[j][i]);
            tc+=m;
            cnt[i][j]-=m;
            cnt[j][i]-=m;
            rm+=cnt[i][j]+cnt[j][i];
        }
    }
    tc+=rm*2/3;
    fout<<tc<<'\n';

}

