/*
ID:haoziyi1
PROG:zerosum
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
ifstream fin("zerosum.in");
ofstream fout("zerosum.out");
int N;
void dfs(int last,int cur,int rem,char path[],int pid)
{
    if(cur==N+1&&rem+last==0)
    {
        if(pid!=0)
        {
            fout<<1;
            for(int i=0;i<pid;i++)
                fout<<path[i]<<i+2;
            fout<<endl;
        }
        return;
    }
    if(cur>N)
        return;
    path[pid]=' ';
    dfs(last>0?last*10+cur:last*10-cur,cur+1,rem,path,pid+1);

    path[pid]='+';
    dfs(cur,cur+1,rem+last,path,pid+1);
    
    path[pid]='-';
    dfs(-cur,cur+1,rem+last,path,pid+1);
    
    
}
int main(){
    fin>>N;
    char path[10];
    dfs(1,2,0,path,0);
}

