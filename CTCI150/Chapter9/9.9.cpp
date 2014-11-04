/*
Auther:haozy
Problem:9.9
Language:C++
Description:eight queens problem
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
int path[100];
int queue(int row,int n,int col,int digl,int digr)
{
    if(row==n)
        return 1;
    int r=0;
    for(int i=0;i<n;i++)
    {
        int cur=1<<i;
        if(col&cur||digl&cur||digr&cur)
            continue;
        path[row]=i;
        r+=queue(row+1,n,col|cur,(digl|cur)<<1,(digr|cur)>>1);
    }
    return r;
}

int main(){
    for(int i=1;i<14;i++)
    {
        cout<<queue(0,i,0,0,0)<<endl;
    }
}

