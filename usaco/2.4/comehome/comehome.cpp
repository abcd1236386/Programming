/*
ID:haoziyi1
PROG:comehome
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
#include<queue>
using namespace std;
ifstream fin("comehome.in");
ofstream fout("comehome.out");
int grp[26*2][26*2]={0};
int id(char x)
{
    if(x<='Z')
        return x-'A';
    return x-'a'+26;
}
char ch(int i)
{
    if(i<26)
        return i+'A';
    else
        return i-26+'a';
}
bool hascow(int x)
{
    return x<25;
}
struct nd{
    int n;
    int d;
    nd(int i,int j){
        n=i;
        d=j;
    }
    bool operator <(const nd & in)const
    {
        return d>in.d;
    }
};
nd bfs(char s)
{
    priority_queue<nd> Q;
    Q.push(nd(id(s),0));
    bool vst[26*2]={0};
    while(!Q.empty())
    {
        nd t=Q.top();Q.pop();
        if(vst[t.n])
            continue;
        vst[t.n]=1;
        if(hascow(t.n))
            return t;
        for(int i=0;i<26*2;i++)
        {
            if(!vst[i]&&i!=t.n&&grp[t.n][i]>0){
                Q.push(nd(i,t.d+grp[t.n][i]));
            }
        }
    }
}
int main(){
    int P;
    fin>>P;
    char a,b;
    int d;
    for(int i=0;i<P;i++)
    {
        fin>>b>>a>>d;
        if(grp[id(a)][id(b)]==0||
            grp[id(a)][id(b)]>d)
        {
            grp[id(a)][id(b)]=d;
            grp[id(b)][id(a)]=d;
        }
    }
    //we have the graph now. do a dijstra.
    nd p=bfs('Z');
    cout<<ch(p.n)<<' '<<p.d<<endl;
    fout<<ch(p.n)<<' '<<p.d<<endl;
}

