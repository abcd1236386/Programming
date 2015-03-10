/*
ID:haoziyi1
PROG:runround
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
ifstream fin("runround.in");
ofstream fout("runround.out");
int used[10]={0,1};
void genX(int x[],int X)
{
    bool ud[10]={0};
    int buf[9];
    int len=0;
    while(X){
        buf[len]=X%10;
        X/=10;
        len++;
    }
    int i=9-len;
    if(i==8)
    {
        x[i]=1;
        return;
    }
    x[i]=buf[len-1]-1;
    int k=9;
    for(i=i+1;i<9;i++)
    {
        if(x[9-len]==k)
            k--;
        x[i]=k;
        k--;
    }
    memset(used,0,sizeof(used));
    for(int j=9-len;j<9;j++)
    {
        used[x[j]]=1;
    }
}
void next(int x[])
{
    bool n=1;
    int i=8;
    int k;
    for(k=x[i]+1;k<=9;k++)
            if(!used[k])
            {
                used[x[i]]=0;
                used[k]=1;
                x[i]=k;
                break;
            }
    if(k!=10)
        return;
    //we should to move forward.
    while(i>0&&x[i]<x[i-1])
    {
        used[x[i]]=false;
        i--;
    }
    used[x[i]]=false;
    //x[i-1]<x[i]. so x[i-1] at least can be x[i];
    for(int j=x[i-1]+1;j<=9;j++)
        if(!used[j])
        {
            used[x[i-1]]=0;
            used[j]=1;
            x[i-1]=j;
            break;
        }
    while(i<9){
        for(int j=1;j<=9;j++)
            if(!used[j])
            {
                used[j]=1;
                x[i]=j;
                break;
            }
        i++;
    }
}
void outN(int x[])
{
    int e=0;
    while(x[e]==0)
        e++;
    while(e<9)
        cout<<x[e++];
    cout<<endl;
}
int toNum(int x[])
{
    int e=0;
    while(x[e]==0)
        e++;
    int r=0;
    while(e<9){
        r*=10;
        r+=x[e++];
    }
    return r;
}
bool valid(int x[])
{
    bool hd[10]={0};
    int off=0;
    int t=0;
    while(x[off]==0)
        off++;
    int len=9-off;
    int i=0;
    while(!hd[i]){
        hd[i]=1;
        t++;
        i=(i+x[i+off])%len;
    }
    return i==0&&t==len;
}
int main(){
    int n;
    fin>>n;
    int cnt=1;
    int t;
    int x[9]={0};
    //memset(used,0,sizeof(used));
    //for(int i=3;i<=9;i++)
    //    used[i]=1;
    genX(x,n);
    do{
        next(x);
        if(valid(x)&&(t=toNum(x))>n)
            break;
       // cout<<t<<endl;
    }while(1);
    fout<<t<<endl;
    
}

