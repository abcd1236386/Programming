#include<iostream>
using namespace std;
int Numbers(int n)
{
    int r=1;
    int res=n;
    while(r<=n/2)
    {
        res=res*(n-r)/(r+1);
        r++;
        if(res>1000000)
        {
            return (n+1-2*r);
        }
    }
    return 0;
}
int main(){
    int t=0;bool first=true;
    for(int i=1;i<=100;i++)
    {
        t+=Numbers(i);
        if(t!=0&&first)
        {
            cout<<i<<endl;
            first=false;
        }
    }
    cout<<t<<endl;
}
