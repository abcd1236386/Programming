/*
ID:haoziyi1
PROG:lamps
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<cstring>
using namespace std;
ifstream fin("lamps.in");
ofstream fout("lamps.out");
int N;
template<int maxn>
struct bitvect{
    unsigned int buf[((maxn-1)>>5)+1];
    int len;
    bitvect(bool b)
    {
        len=((maxn-1)>>5)+1;
        if(b)
            memset(buf,-1,sizeof(buf));
        else
            memset(buf,0,sizeof(buf));
    }
    bool get(int i) const
    {
        return buf[i>>5]&(1<<(i&0x1f));
    }
    void set(int i,bool f)
    {
        if(f)
            buf[i>>5]|=1<<(i&0x1f);
        else
            buf[i>>5]&=~(1<<(i&0x1f));

    }
    void b1()
    {
        for(int i=0;i<len;i++)
            buf[i]=~buf[i];
    }
    void b2()
    {
        for(int i=0;i<maxn;i+=2)
        {
            bool b=get(i);
            set(i,!b);
        }
    }
    void b3()
    {
        for(int i=1;i<maxn;i+=2)
        {
            bool b=get(i);
            set(i,!b);
        }
    }
    void b4()
    {
        for(int i=0;i<maxn;i+=3)
        {
            bool b=get(i);
            set(i,!b);
        }
    }
    bool allzero(bitvect &bv)
    {
        for(int i=0;i<len;i++)
            if(buf[i]&bv.buf[i])
                return false;
        return true;
    }
    bool allone(bitvect & bv)
    {
        for(int i=0;i<len;i++)
            if(~(buf[i]|(~bv.buf[i])))
                return false;
         return true;
    }
    void setall(bool b)
    {
        if(b)
            memset(buf,-1,sizeof(buf));
        else
            memset(buf,0,sizeof(buf));
        
    }
    void bx(int x)
    {
        if(x==0)
            b1();
        else if(x==1)
            b2();
        else if(x==2)
            b3();
        else
            b4();
    }
    void list(int n)
    {
        for(int i=0;i<4;i++)
        {
            if(n&(1<<i))
            {
                bx(i);
            }
        }
    }
    bool operator<(const bitvect& vb)const{
        for(int i=0;i<N;i++)
            if(get(i)<vb.get(i))
                return true;
            else if(get(i)>vb.get(i))
                return false;
        return false;
    }
};
int main(){
    int C;
    bitvect<100> zero(0);
    bitvect<100> one(0);
    fin>>N>>C;
    int t;
    while(fin>>t,t!=-1)
    {
        one.set(t-1,1);
    }
    while(fin>>t,t!=-1)
    {
        zero.set(t-1,1);
    }
    vector<bitvect<100> > vb;
    //check C
    bitvect<100> x(1);
    if(C&1)// for odd
    {
        //1,2,4,8,14,13,11,7
        int todo[8]={1,2,4,8,14,13,11,7};
        for(int i=0;i<8;i++)
        {
            if(i>=4&&C<3)
                break;
        x.list(todo[i]);
        if(x.allzero(zero)&&x.allone(one))
            vb.push_back(x);
        x.setall(1);
        }
    }
    else
    {
        //0,15,3,5,6,9,10,12,
        int todo[8]={0,3,5,6,9,10,12,15};
        for(int i=0;i<8;i++)
        {
            if(i>=1&&C<2||i>=7&&C<4)
                break;
        x.list(todo[i]);
        if(x.allzero(zero)&&x.allone(one))
            vb.push_back(x);
        x.setall(1);
        }
    
    }
    sort(vb.begin(),vb.end());
    for(int i=0;i<vb.size();i++)
    {
        for(int j=0;j<N;j++)
        {
            fout<<vb[i].get(j);
        }
        fout<<endl;
    }
    if(vb.size()==0)
        fout<<"IMPOSSIBLE\n";
}

