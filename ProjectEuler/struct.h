#include<iostream>
#include<cmath>
using namespace std;
template<int maxn>
struct Prime{
    int buf[maxn];
    void generate(){
        int i=0;
        buf[i]=2;
        i++;
        int num=3;
        while(i<maxn)
        {
            bool ip=true;
            for(int j=0;buf[j]<=num/2;j++)
                if(num%buf[j]==0){
                    ip=false;
                    break;
                }
            if(ip)
                buf[i++]=num;
            num++;
        }
    }
    int getGreater(int x)//return the min(y E p,y>=x),and 
    {
        //loop invariout ..p[l]<x<=p[r]
        int l=-1,r=maxn;
        while(l+1<r)
        {
            int md=(l+r)/2;
            if(buf[md]<x)
                l=md;
            else
                r=md;
        }
        return buf[r];
    }
    //
    bool isPrime(int num){
       if(buf[maxn-1]<num)
       {
           //use other functons to calulate.
           if(num%2==0)
               return false;
           if(num%3==0)
               return false;
           for(int i=1;;i++)
           {
               int k=6*i-1;
               if(k>sqrt(num))
                   break;
               if(num%k==0)
                   return false;
               k=6*i+1;
               if(k>sqrt(num))
                   break;
               if(num%k==0)
                   return false;

           }
           return true;
           //    throw "out of range";
        }
        int i=0,j=maxn-1;
        while(i<=j)
        {
            int md=(i+j)/2;
            if(buf[md]==num)
                return true;
            else if(buf[md]>num)
                j=md-1;
            else
                i=md+1;
        }
        return false;
    }
    void outputSample(){
        for(int i=0;i<10;i++)
            cout<<buf[i]<<' ';
         cout<<endl;
    }
    void testcase(){
        for(int i=0;i<20;i++)
        {
            if(isPrime(i))
                cout<<i<<" Yes\n";
             else cout<<i<<"No\n";
        }
    }
};
