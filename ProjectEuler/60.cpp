#include"struct.h"
#include<iostream>
using namespace std;
Prime<10000> prm;
void concat(int a,int b,int & ab,int &ba)
{
    int t=b;
    ab=a;
    while(t)
    {
        ab*=10;
        t/=10;
    }
    ab+=b;
    t=a;
    ba=b;
    while(t)
    {
        ba*=10;
        t/=10;
    }
    ba+=a;
}
bool allPrime(int *buf,int i,int j,int k,int l,int m)
{
    int ab,ba;
    concat(buf[i],buf[j],ab,ba);
    if(!prm.isPrime(ab)||!prm.isPrime(ba))
        return false;
    concat(buf[i],buf[k],ab,ba);
    if(!prm.isPrime(ab)||!prm.isPrime(ba))
        return false;
    concat(buf[i],buf[l],ab,ba);
    if(!prm.isPrime(ab)||!prm.isPrime(ba))
        return false;
    concat(buf[i],buf[m],ab,ba);
    if(!prm.isPrime(ab)||!prm.isPrime(ba))
        return false;
    concat(buf[j],buf[k],ab,ba);
    if(!prm.isPrime(ab)||!prm.isPrime(ba))
        return false;
    concat(buf[j],buf[l],ab,ba);
    if(!prm.isPrime(ab)||!prm.isPrime(ba))
        return false;
    concat(buf[j],buf[m],ab,ba);
    if(!prm.isPrime(ab)||!prm.isPrime(ba))
        return false;
    concat(buf[k],buf[l],ab,ba);
    if(!prm.isPrime(ab)||!prm.isPrime(ba))
        return false;
    concat(buf[k],buf[m],ab,ba);
    if(!prm.isPrime(ab)||!prm.isPrime(ba))
        return false;
    concat(buf[l],buf[m],ab,ba);
    if(!prm.isPrime(ab)||!prm.isPrime(ba))
        return false;
    return true;
}
int lastm=4;
void findlowest(int *buf,int i,int j,int k,int l,int m,int max)
{
    if(allPrime(buf,i,j,k,l,m))
        cout<<buf[i]+buf[j]+buf[k]+buf[l]+buf[m]<<endl;
    cout<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<m<<'\n';
    cin.get();
    if(m==max&&m==i+4)
        return;
    if(i+1<j)
        findlowest(buf,i+1,j,k,l,m,max);
    if(j+1<k)
        findlowest(buf,i,j+1,k,l,m,max);
    if(k+1<l)
        findlowest(buf,i,j,k+1,l,m,max);
    if(l+1<m)
        findlowest(buf,i,j,k,l+1,m,max);
    if(m+1<=max)
        findlowest(buf,i,j,k,l,m+1,max);

}
int main(){
    prm.generate();
    findlowest(prm.buf,0,1,2,3,4,100);
}
