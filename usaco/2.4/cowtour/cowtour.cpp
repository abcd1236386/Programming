/*
ID:haoziyi1
PROG:cowtour
LANG:C++
*/
#include<cmath>
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<cstring>
using namespace std;
ifstream fin("cowtour.in");
ofstream fout("cowtour.out");
double dist[150][150]={0};
int N;
int x[150],y[150];
double maxd[150]={0};// maxd[i] means the max len from i
int st[150]={0};
int sid=1;
double getd(int i,int j)
{
    return sqrt(double(x[i]-x[j])*double(x[i]-x[j])
    +double(y[i]-y[j])*double(y[i]-y[j]));
}
void dijkstra(int i){
    int s=i;
    double nd[150]={0};
    for(int j=0;j<N;j++)
        nd[j]=-1;
    bool vst[150]={0};
    nd[s]=0;
    vst[s]=1;
    while(i!=-1){
	vst[i]=1;
        for(int j=0;j<N;j++)
        {
            if(!vst[j]&&dist[i][j]>0&&(nd[j]<0||dist[i][j]+nd[i]<nd[j]))
                nd[j]=dist[i][j]+nd[i];
        }
        //find next i
        i=-1;
        for(int j=0;j<N;j++)
        {
            if(!vst[j]&&nd[j]>0)
            {
                if(i==-1||nd[i]>nd[j])
                    i=j;
            }
        }
    }//
    i=s;
    if(st[s]==0)
        st[s]=sid++;
    for(int j=0;j<N;j++){
        if(nd[j]>0)
            st[j]=st[s];

        if(maxd[s]<nd[j]){
            maxd[s]=nd[j];
            i=j;
        }
    }
    
}
int main(){
    fin>>N;
    for(int i=0;i<N;i++){
        fin>>x[i]>>y[i];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
        {
            char ch;fin>>ch;
            dist[i][j]=-1;
            if(ch=='1')
                dist[i][j]=dist[j][i]=getd(i,j);
        }
    }
    //calculate all the
    for(int i=0;i<N;i++)
        dijkstra(i);
    //check all the others.
    double mi=-1;    
    double mx=-1;
    for(int i=0;i<N;i++)
    {
        if(mx==-1||mx<maxd[i])
            mx=maxd[i];
        for(int j=i+1;j<N;j++)
        {
            if(st[i]!=st[j])
            {
                double xd=maxd[i]+maxd[j]+getd(i,j);
                if(mi<0||mi>xd)
                    mi=xd;
            }
        }
    }
    char str[100];
    sprintf(str,"%.6lf",max(mi,mx));
    fout<<str<<endl;
}

