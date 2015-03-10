/*
ID:haoziyi1
PROG:butter
LANG:C++
*/
#include<iostream>
#include<queue>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<cstring>
using namespace std;
ifstream fin("butter.in");
ofstream fout("butter.out");
struct nd{
    int id;
    int val;
    nd(int i,int v){
        id=i;
        val=v;
    }
    operator int ()const {
        return val;
    }
    bool operator <(const nd& n)const {
      return  val>n.val;
    }
};
int path[800+1][800+1];
int cows[801]={0};
int dist[801];
vector<int> nei[801];
bool visit[801];
int dijkstra(int s)
{
    memset(dist,-1,sizeof(dist));
    memset(visit,0,sizeof(visit));
    dist[s]=0;
    priority_queue<nd> mh;
    mh.push(nd(s,0));
    while(!mh.empty()){
        nd t=mh.top();mh.pop();
        if(visit[t.id])
            continue;
        visit[t.id]=1;
        for(int i=0;i<nei[t.id].size();i++){
            int j=nei[t.id][i];
            if(dist[j]==-1||dist[j]>dist[t.id]+path[t.id][j]){
                dist[j]=dist[t.id]+path[t.id][j];
                mh.push(nd(j,dist[j]));
            }
        }
    }
    int t=0;
    for(int i=0;i<801;i++){
        if(dist[i]!=-1)
            t+=dist[i]*cows[i];
    }
    return t;
}
int main(){
   int N,P,C;
   fin>>N>>P>>C;
   for(int i=0;i<N;i++)
   {
       int c;fin>>c;
       cows[c]++;
   }
   memset(path,-1,sizeof(path));
   for(int i=1;i<=P;i++){
       path[i][i]=0;
   }
   for(int i=0;i<C;i++)
   {
       int a,b,c;
       fin>>a>>b>>c;
       path[a][b]=path[b][a]=c;
	nei[a].push_back(b);
	   nei[b].push_back(a);
   }
   //floyd, D(i,j,k) means from i to j ,use only node (1..k) the min paht.
   //so D(i,j,k)=min(D(i,k,k-1)+D(k,j,k-1),D(i,j,k-1));
   //we check all the node to find a min
   int mi=-1;
   for(int i=1;i<=P;i++){
       int t=dijkstra(i);
       if(mi==-1||mi>t)
           mi=t;
   }
   fout<<mi<<endl;
   cout<<mi<<endl;
}

