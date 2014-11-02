/*
Auther:haozy
Problem:5.3
Language:C++
Description:find next smallest and largest that have same number of 1
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
int smallestLarger(int x)
{
    //we find the first zero after one.
    //then we swap it with the one after it.
    int i=0;
    int zr=0;
    while((x&(1<<i))==0){
        i++;
        zr++;
    }
    //we find a one.
    //from (i..0] all is zero
    while(x&(1<<(i+1)))
        i++;
    //i is the last one.
    int mask=~0<<i;
    int last=~mask&x;
    //we find a zero.
    return ((mask&x)^((1<<i)|(1<<i+1)))|(last>>zr);
}
int largestSamller(int x)
{
    //find the firset one after zero.
    int i=0;
    int zr=0;
    while((x&(1<<i))){
        i++;
    }
    //we find a zero.
    while(!(x&(1<<(i+1)))){
        i++;
        zr++;
    }
    //i is the last one.
    int mask=~0<<i;
    int last=~mask&x;
    //we find a zero.
    return ((mask&x)^((1<<i)|(1<<i+1)))|(last<<zr);
}
int main(){
    int x=3;
    for(int i=0;i<5;i++)
    {
        x=smallestLarger(x);
        cout<<x<<endl;
    }
    for(int i=0;i<5;i++)
    {
        x=largestSamller(x);
        cout<<x<<endl;
    }
}

