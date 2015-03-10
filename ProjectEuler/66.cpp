#include<iostream>
#include<cmath>
#include<climits>
using namespace std;
bool issquare(long long x,int &y)
{
    y=sqrt((double)x);
    return (y*y==x);

}
int findminx(int d)
{
    int y=1;
    int x=0;
    long long t;
    do{
        t=1+d*y*y;
        y++;
    }while(!issquare(t,x));
    return x;
        
}
int main(){
    int maxx=0;
    int t;
    for(int d=2;d<=1000;d++)
    {
        if(!issquare(d,t))
        {
         int x=findminx(d);
         if(maxx<x)
          {
             maxx=x;
             cout<<d<<' '<<maxx<<endl;
          }
        }
    }
}
