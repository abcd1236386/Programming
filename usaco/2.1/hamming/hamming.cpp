/*
ID:haoziyi1
PROG:hamming
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
ifstream fin("hamming.in");
ofstream fout("hamming.out");
int ones[256];
void initOnes(){
    ones[0]=0;
    for(int i=1;i<256;i++)
        ones[i]=ones[i&(i-1)]+1;
}
int hammingDist(int a,int b)
{
    return ones[a^b];
}
int N,B,D;
int path[64];
bool valid(int len,int x)
{
    for(int i=0;i<len;i++)
    {
        if(hammingDist(path[i],x)<D)
            return false;
    }
    return true;
}
bool valid(vector<int> &vi,int x)
{
    for(int i=0;i<vi.size();i++)
    {
        if(hammingDist(vi[i],x)<D)
            return false;
    }
    return true;

}
bool bfs(int max){
    queue<vector<int> > Q;
    vector<int> v(1);
    int last=0;
    for(int i=0;i<max;i++)
    {
        v[0]=i;
        Q.push(v);
    }
    while(!Q.empty())
    {
        vector<int> & t=Q.front();
        if(t.size()!=last)
        {
            last=t.size();
            cout<<t.size()<<endl;
        }
        if(t.size()==N)
        {
            for(int i=0;i<t.size();i++)
                path[i]=t[i];
            break;
        }
        //gen next.
        int start=t.back()+1;
        for(int i=start;i<max;i++)
        {
            if(valid(t,i))
            {
                t.push_back(i);
                Q.push(t);
                t.pop_back();
            }
        }
        //pop Q
        Q.pop();
    }
}
bool dfs(int pid,int c,int max)
{
    if(pid==N)
    {
        return true;
    }
    if(c>=max)
        return false;
    //shi fou neng yao c.
    for(int i=c;i<max;i++)
    {
        if(valid(pid,i))
        {
            path[pid]=i;
            if(dfs(pid+1,i+1,max))
                return true;
        }
    }
    return false;
}
int main(){
    initOnes();
    fin>>N>>B>>D;
    dfs(0,0,1<<B);
    for(int i=0;i<N;i++)
    {
        fout<<path[i];
        if(i==N-1)
            fout<<endl;
        else if((i+1)%10==0)
            fout<<endl;
        else
            fout<<' ';
    }
}

