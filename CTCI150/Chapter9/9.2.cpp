/*
Auther:haozy
Problem:9.2
Language:C++
Description:from (0,0) to (x,y) to find the ways
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
int ways(int x,int y)
{
    
    //for we have x right a,d y down, so the total way is C(x+y,x);
    //as for if we have C(x-1+y-1,x-1) the we find that C(x+y,x)=(x+y)*(x+y-1)/x/y*C(x+y-2,x-1);
    // as we know ,C(k,0)=1. so we can do this from C(y,0) to C(x+y,x);
    // as x,y is same as y,x ,so we may assume that x<y
    //so the time complexy is O(min(x,y))
    //
    if(x>y)
        swap(x,y);
    int c=1;
    for(int i=1;i<=x;i++)
    {
        c=c*(i+y)/i;
    }
    return c;
}
//if it has some off limits .we must use DP to solve this solution.
//if(!limits(i,j)) 
//     f(i,j)=f(i-1,j)+f(i,j-1);
// else
//      f(i,j)=0;
int main(){
    cout<<ways(3,5)<<endl;
}

