/*
ID:haoziyi1
PROG:agrinet
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
ifstream fin("agrinet.in");
ofstream fout("agrinet.out");
template<int maxn>
struct UnionFind{
    int fa[maxn];
    UnionFind(){
        for(int i=0;i<maxn;i++)
            fa[i]=i;
    }
    int find(int x)
    {
        if(x!=fa[x])
            fa[x]=find(fa[x]);
        return fa[x];
    }
    bool Union(int x,int y)
    {
        int fx=find(x);
        int fy=find(y);
        if(fx!=fy)
        {
            fa[fy]=fx;
            return true;
        }
        return false;
    }
};
struct eg{
    int v;
    int x,y;
}edg[100*100];
bool cmp(const eg& e1,const eg&e2)
{
    return e1.v<e2.v;
}
int main(){
    int n,v;
    fin>>n;
    int en=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            fin>>v;
            if(j<=i)
                continue;
            edg[en].v=v;
            edg[en].x=i;
            edg[en].y=j;
            en++;
        }
    }
    //
    sort(edg,edg+en,cmp);
    int eslc=0;
    UnionFind<100> uf;
    int cost=0;
    for(int i=0;i<en&&eslc<en-1;i++)
    {
        if(uf.Union(edg[i].x,edg[i].y)){
            cost+=edg[i].v;
            eslc++;
        }
    }
    fout<<cost<<endl;
}

