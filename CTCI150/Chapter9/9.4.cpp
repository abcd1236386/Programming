/*
Auther:haozy
Problem:9.4
Language:C++
Description:return all subset of a set
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include"../struct.h"
#include<ctime>
using namespace std;
int cnt1=0,cnt2=0;
void subset(int st[],int n,int c,int path[],int pid)
{
    if(c==n)
    {
        //we find a subset.
       /* if(pid==0)
            cout<<"O";
        for(int i=0;i<pid;i++)
        {
            cout<<path[i]<<' ';
        }
        cout<<endl;*/
        cnt1++;
        return;
    }
    subset(st,n,c+1,path,pid);
    path[pid]=st[c];
    subset(st,n,c+1,path,pid+1);
}
void subset2(int st[],int n,int c,int path[],int pid)
{
    if(n==c)
    {
        //we find a subset.
        /*if(pid==0)
            cout<<"O";
        for(int i=0;i<pid;i++)
        {
            cout<<path[i]<<' ';
        }
        cout<<endl;*/
        cnt2++;
        return;

    }
    for(int i=c;i<n;i++)
    {
        path[pid]=st[i];
        subset2(st,n,i+1,path,pid+1);
    }
    //or skip all the number
    subset2(st,n,n,path,pid);
}

int main(){
    int n=12;
    int st[n];
    for(int i=0;i<n;i++)
        st[i]=i+1;
    int path[n];
    clock_t t=clock();
    subset(st,n,0,path,0);
    cout<<cnt1<<endl;
    cout<<"time:"<<clock()-t<<endl;
    cout<<"-------vs---------\n";
    t=clock();
    subset2(st,n,0,path,0);
    cout<<cnt2<<endl;
    cout<<"time:"<<clock()-t<<endl;
}

