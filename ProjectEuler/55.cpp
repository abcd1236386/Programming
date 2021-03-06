#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>

using namespace std;
template<int maxn>
struct bint{
    unsigned char num [maxn];
    int len;
    bint(){
        len=1;
        memset(num,0,sizeof(num));
        }
    bint & operator =(int i)
    {
        memset(num,0,sizeof(num));
        len=0;
        while(i){
            num[len++]=i%10;
            i/=10;
        }
        if(len==0)
            len=1;
        return *this;
    }
    bint &operator +=(const bint& bi)
    {
        if(len<bi.len)
            len=bi.len;
        for(int i=0;i<len;i++)
        {
            num[i]+=bi.num[i];
            num[i+1]+=num[i]/10;
            num[i]%=10;
        }
        if(num[len]!=0)
            len++;
		return *this;
    }
    void ReverseAdd()
    {
		bint b=reverse();
		*this+=b;
    }
    bint reverse()
    {
        bint t;
        t.len=len;
        for(int i=0;i<len;i++)
            t.num[i]=num[len-1-i];
		return t;
    }
    bool palindromic()
    {
        int i=0,j=len-1;
        while(i<j){
            if(num[i]!=num[j])
                return false;
            i++;
            j--;
           }
       return true;
    }
	 template<int mn>
  friend ostream & operator <<(ostream &out,const bint<mn>& b);

};
 template<int maxn>
 ostream & operator <<(ostream &out,const bint<maxn>& b)
  {
        for(int i=b.len-1;i>=0;i--)
            out<<(int)(b.num[i]);
		return out;
 }
bint<100> i;
int main(){
    int j=196;
    int cnt=0;
    while(j<10000)
    {
        i=j;
        int t=49;
        while(t--)
        {

            i.ReverseAdd();
            if(i.palindromic())
             {
              //   cnt++;
                break;
             }
        }
		
        if(t<0)
         {
             cout<<j<<endl;
             cnt++;
         }
		j++;
    }
    cout<<cnt<<endl;
}
