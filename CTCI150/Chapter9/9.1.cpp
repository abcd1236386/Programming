/*
Auther:haozy
Problem:9.1
Language:C++
Description:running up stair, either 1 or 2 or 3 step.
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
//for the stair n,we have the way f(n)=f(n-1)+f(n-2)+f(n-3);
int step(int n)
{
    int f[4];
    f[0]=1;
    f[1]=1;
    f[2]=2;
    for(int i=3;i<=n;i++)
    {
        f[i%4]=f[(i-1)%4]+f[(i-2)%4]+f[(i-3)%4];
    }
    return f[n%4];
}

int main(){
    for(int i=1;i<=10;i++)
        cout<<step(i)<<endl;
}

