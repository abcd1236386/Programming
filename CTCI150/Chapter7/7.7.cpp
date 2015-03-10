/*
Auther:haozy
Problem:7.7
Language:C++
Description:kth number only prime factor are 3 5 7
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
using namespace std;
vector<int> v;
int min3(int a,int b,int c)
{
    return min(a,min(c,b));
}
void naive(int k)
{
    int t=0;
    vector<int> v;
    for(int i=1;t<=k;i++)
    {
        int c=i;
        while(c%3==0)
            c/=3;
        while(c%5==0)
            c/=5;
        while(c%7==0)
            c/=7;
        if(c==1){
            v.push_back(i);
            t++;
        }
    }
    for(int i=0;i<=k;i++)
        cout<<v[i]<<' ';
    cout<<endl;
}
int main(){
    int k;cin>>k;
    int p3=0,p5=0,p7=0;
    int c=1;
    v.push_back(1);
    for(int i=1;i<=k;i++)
    {
        int t=min3(v[p3]*3,v[p5]*5,v[p7]*7);
        v.push_back(t);
        if(v[p3]*3==v.back())
            p3++;
        if(v[p5]*5==v.back())
            p5++;
        if(v[p7]*7==v.back())
            p7++;
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<' ';
    }
    cout<<endl;
    naive(k);
}

