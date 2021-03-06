/*
ID:haoziyi1
PROG:msquare
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
ifstream fin("msquare.in");
ofstream fout("msquare.out");
struct cube{
    int b;
    int stp;
    vector<char> path;
    cube(int x=0,int s=0){
        b=x;
        stp=s;
    }
    int get(int i){
        return (b>>3*i)&0x07;
    }
    void set(int i,int y){
        b&=~(0x07<<3*i);
        b|=y<<3*i;
    }
    operator int (){
        return b;
    }
    cube fA(){
        cube t(0,stp+1);
        for(int i=0;i<8;i++){
            t.set(i,get(7-i));
        }
        return t;
    }
    cube fB(){
        cube t(0,stp+1);
        for(int i=1;i<4;i++)
        {
            t.set(i,get(i-1));
            t.set(7-i,get(8-i));
        }
        t.set(0,get(3));
        t.set(7,get(4));
        return t;
    }
    cube fC(){
        cube t(b,stp+1);
        t.set(1,get(6));
        t.set(2,get(1));
        t.set(5,get(2));
        t.set(6,get(5));
        return t;
    }
};
set<int> vist;
bool dfs(cube c,cube g,char path[],int cstp,const int maxs)
{
    if(cstp>maxs)
        return 0;
    if(c==g){
        fout<<cstp<<'\n';
        for(int i=0;i<cstp;i++)
            fout<<path[i];
        fout<<'\n';
        return 1;
    }
    cube t=c.fA();
    if(vist.find(t)==vist.end())
    {
        vist.insert(t);
        path[cstp]='A';
        if(dfs(t,g,path,cstp+1,maxs))
            return true;
        vist.erase(t);
    }
    t=c.fB();
    if(vist.find(t)==vist.end())
    {
        vist.insert(t);
        path[cstp]='B';
        if(dfs(t,g,path,cstp+1,maxs))
            return true;
        vist.erase(t);
    }
    t=c.fC();
    if(vist.find(t)==vist.end())
    {
        vist.insert(t);
        path[cstp]='C';
        if(dfs(t,g,path,cstp+1,maxs))
            return true;
        vist.erase(t);
    }
    return false;
}
int main(){
    cube c,g;
    for(int i=0;i<8;i++){
        c.set(i,i);
        int x;fin>>x;
        g.set(i,x-1);
    }
    queue<cube> q;
    set<int> s;
    q.push(c);
    s.insert(c);
    int STP=-1;
    while(!q.empty()){
        cube t=q.front();q.pop();
        if(t==g){
            STP=t.stp;
            fout<<t.stp<<'\n';
            for(int i=0;i<t.path.size();i++)
                fout<<t.path[i];
            fout<<'\n';
            break;
        }
        cube nt=t.fA();
        if(s.find(nt)==s.end()){
            s.insert(nt);
            nt.path=t.path;
            nt.path.push_back('A');
            q.push(nt);
        }
        nt=t.fB();
        if(s.find(nt)==s.end()){
            s.insert(nt);
            nt.path=t.path;
            nt.path.push_back('B');
            q.push(nt);
        }
        nt=t.fC();
        if(s.find(nt)==s.end()){
            s.insert(nt);
            nt.path=t.path;
            nt.path.push_back('C');
            q.push(nt);
        }
    }//while
    //use dfs to find a path.

    

}

