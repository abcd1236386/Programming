/*
ID:haoziyi1
PROG:fence
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
#include<stack>
using namespace std;
ifstream fin("fence.in");
ofstream fout("fence.out");
vector<int> nei[501];
int con[501][501]={0};
void euler(int s)
{
    vector<int> path;
    stack<int> stk;
    stk.push(s);
    while(!stk.empty()){
        int t=stk.top();
        for(int i=0;i<nei[t].size();i++){
            if(con[t][nei[t][i]]){
                stk.push(nei[t][i]);
                con[t][nei[t][i]]--;
                con[nei[t][i]][t]--;
                break;
            }
        }
        if(t==stk.top())//don't have neigbour
        {
            path.push_back(t);
            stk.pop();
        }
    }
    for(int i=path.size()-1;i>=0;i--)
        fout<<path[i]<<'\n';
}
int main(){
    int f,a,b;
    fin>>f;
    for(int i=0;i<f;i++){
        fin>>a>>b;
        nei[a].push_back(b);
        nei[b].push_back(a);
        con[a][b]++;
        con[b][a]++;
    }
    int start=-1;
    for(int i=0;i<501;i++){
        sort(nei[i].begin(),nei[i].end());
    }
    for(int i=1;i<501;i++){
        if(nei[i].size()%2){
            start=i;
            break;
        }
        if(start==-1&&nei[i].size()!=0){
            start=i;
        }
    }
    //find the euler path.
    euler(start);

}

