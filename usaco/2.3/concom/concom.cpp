/*
ID:haoziyi1
PROG:concom
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<cstring>
using namespace std;
ifstream fin("concom.in");
ofstream fout("concom.out");
struct eg{
    int n;
    int p;
    eg(int i,int j){
        n=i;
        p=j;
    }

};
vector<eg> edge[101];
vector<int> control[101];
void solve(int n)
{
    queue<int> q;
    q.push(n);
    int ct[101]={0};
    bool visit[101]={0};
    visit[n]=1;
    while(!q.empty())
    {
        int c=q.front();q.pop();
        for(int i=0;i<edge[c].size();i++)
        {
            eg tmp=edge[c][i];
            ct[tmp.n]+=tmp.p;
            if(!visit[tmp.n]&&ct[tmp.n]>50){
                q.push(tmp.n);
                visit[tmp.n]=1;
            }
        }
    }
    for(int i=1;i<101;i++)
    {
        if(i==n)
            continue;
        if(ct[i]>50)
            control[n].push_back(i);
    }
}
int main(){
    int n,a,b,c;
    fin>>n;
    for(int i=0;i<n;i++)
    {
       fin>>a>>b>>c;
       edge[a].push_back(eg(b,c));
    }
    //
    for(int i=1;i<=100;i++)
    {
        solve(i);
        for(int j=0;j<control[i].size();j++)
        {
            fout<<i<<' '<<control[i][j]<<'\n';
        }
    }
}

