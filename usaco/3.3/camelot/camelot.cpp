/*
ID:haoziyi1
PROG:camelot
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<string>
#include<cstring>
using namespace std;
ifstream fin("camelot.in");
ofstream fout("camelot.out");
int mp[26][30]={0};
int cnt[26][30]={0};
bool vst[26][30];
int R,C;
bool ok(int i,int j){
    if(i<0||j<0||i>=R||j>=C||vst[i][j])
        return false;
    return true;
}
struct nd{
    int i,j;
    int s;
    nd(int ii,int jj,int ss){
        i=ii;
        j=jj;
        s=ss;
    }
};
void handle(int i,int j,bool knight){
     queue<nd> q;
     memset(vst,0,sizeof(vst));
     q.push(nd(i,j,0));
     while(!q.empty()){
        nd t=q.front();q.pop();
        cnt[t.i][t.j]++;
        mp[t.i][t.j]+=t.s;
        if(knight){
        int ni[8]={-2,-1,1,2,2,1,-1,-2};
        int nj[8]={1,2,2,1,-1,-2,-2,-1};
        for(int i=0;i<8;i++){
            if(ok(t.i+ni[i],t.j+nj[i]))
            {
                vst[t.i+ni[i]][t.j+nj[i]]=1;
                q.push(nd(t.i+ni[i],t.j+nj[i],t.s+1));
            }
        }
        }
        else{
        int ni[8]={-1,-1,-1,0,0,1,1,1};
        int nj[8]={-1,0,1,-1,1,-1,0,1};
        for(int i=0;i<8;i++){
            if(ok(t.i+ni[i],t.j+nj[i]))
            {
                vst[t.i+ni[i]][t.j+nj[i]]=1;
                q.push(nd(t.i+ni[i],t.j+nj[i],t.s+1));
            }
        }
        }
     }
}
int main(){
    fin>>R>>C;
    char r;
    int c;
    int ct=1;
    fin>>r>>c;
    handle(r-'A',c-1,false);
    cout<<mp[1][4]<<endl;
    while(fin>>r>>c){
        handle(r-'A',c-1,true);
        cout<<mp[1][4]<<endl;
        ct++;
    }
    int mi=-1;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(cnt[i][j]==ct&&(mi==-1||mi>mp[i][j])){
                mi=mp[i][j];
                cout<<mi<<' '<<char(i+'A')<<' '<<j+1<<endl;
            }
        }
    }
    fout<<mi<<endl;
}

