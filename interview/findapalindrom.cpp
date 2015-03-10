#include<cstring>
#include<iostream>
using namespace std;
int s=0;
void dfs(int path[],int cur,int maxn)
{
    if(cur==0){
        //for(int i=0;i<maxn*2;i++){
         //   cout<<path[i]<<' ';
       // }
        //cout<<endl;
        s++;
        return;
    }
    for(int i=0;i+cur+1<2*maxn;i++)
    {
        if(path[i]==0&&path[i+cur+1]==0){
            path[i]=path[i+cur+1]=cur;
            dfs(path,cur-1,maxn);
            path[i]=path[i+cur+1]=0;
        }
    }

}
int main(){
    int n;cin>>n;
    int path[2*n];
    memset(path,0,sizeof(path));
    dfs(path,n,n);
    cout<<s<<endl;
}
