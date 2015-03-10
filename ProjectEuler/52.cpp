#include<iostream>
using namespace std;
void split(int n,char num[10])
{
    for(int i=0;i<10;i++)
        num[i]=0;
    while(n)
    {
        num[n%10]++;
        n/=10;
    }
}
bool same(char *n1,char *n2)
{
    for(int i=0;i<10;i++)
        if(n1[i]!=n2[i])
            return false;
    return true;
}
int main(){
    int x=1;
    char x2[10];
    char xx[10];
    while(1){
        split(2*x,x2);
        int i=3;
        for(;i<7;i++)
        {
            split(i*x,xx);
            if(!same(x2,xx))
                break;
        }
        if(i==7)
        {
            cout<<x<<endl;
            break;
        }
        x++;
        if(x%1000==0)
            cout<<x<<endl;
    }
}
