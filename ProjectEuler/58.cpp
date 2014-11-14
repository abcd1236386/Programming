#include "struct.h"
#include<iostream>
using namespace std;
const int mx=20;
Prime<mx> prm;
int main(){
    prm.generate();
    prm.outputSample();
    prm.testcase();
    cout<<"generate over,max is :"<<prm.buf[mx-1]<<endl;
    int p=0,t=1,l=1;
    double tostop=0.1;
    cin>>tostop;
    while(1){
        l+=2;
        int f=l*l;
        if(prm.isPrime(f-(l-1)*1))
            p++;
        if(prm.isPrime(f-(l-1)*2))
            p++;
        if(prm.isPrime(f-(l-1)*3))
            p++;

        t+=4;
        cout<<(double)p/t*100<<"% "<<f<<"\n";
        if((double)p/t<tostop)
        {
            cout<<l<<endl;
            break;
        }
    }
}
