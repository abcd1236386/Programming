/*
Auther:haozy
Problem:13.10
Language:C++
Description:implement a two dimensional array,can be accessed by notation arr[i][j]
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
int **my2DAlloc(int m,int n)
{
    //we can use a 
    // we should use a m*n+m size.
    int **rowptr=new int*[m*n+m];
    int *buf=(int*)(rowptr+m);
    for(int i=0;i<m;i++)
    {
        rowptr[i]=buf+i*n;
    }
    return rowptr;
}

int main(){
    //if we access it ,we should use:
    int **t=my2DAlloc(3,5);
    t[2][3]=4;
    cout<<t[2][3]<<endl;
}

