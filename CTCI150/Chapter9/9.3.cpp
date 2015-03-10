/*
Auther:haozy
Problem:9.3
Language:C++
Description:sorted array of distinct integers ,find a magic index ,where A[i]=i
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
// array is dinstict integers, and soted .
// the index is x-axis ,value is y-axis, problem is find the intersect of y=x and y=a[x].
// as the y=a[i] is a little strange ,it at least increased by one ,so it or paralle with y=x ,or
// increase more than y=x.
// so it will have exactly one point or all point .after it .
// so we can use binary search ,if a[i] >i ,it will not intersect again. so must in the left.
//
int bfind(int a[],int n)
{
    //we asume that a[l]<i<=a[r]
    int l=-1;
    int r=n;
    while(l+1<r){
        int m=(l+r)/2;
        if(a[m]<m)
            l=m;
        else
            r=m;
    }
    //a[l]<i<=a[l+1]
    // so r is the first element.
    return r==n?-1:r; 
}
//if it have duplicate value . the slope can range from zero to infinit .so it my be have multipul 
//intersect. and we don't know whether to find it .
//we must interat to find one.but we can skip some case. when we search form left to right.if a[i]>i
//so the least to next candidate is a[i]-i.
int iterfind(int a[],int n)
{
    int i=0;
    while(i<n){
        if(a[i]==i)
            return i;
        if(a[i]<i)
            i++;
        else
            i+=(a[i]-i);
    }
    return -1;
}
int main(){

}

