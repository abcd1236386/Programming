/*
Auther:haozy
Problem:13.8
Language:C++
Description:implement smart pointer
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
template<typename T>
class smartptr{
    T * origptr;
    int * cnt;
    public:
    explicit smartptr(T * ptr=NULL){
        origptr=ptr;
        cnt=0;
        ref();
    }
    smartptr<T>(const smartptr<T> &cp){
        if(origptr==cp.origptr)
            return;
        deref();
        origptr=cp.origptr;
        cnt=cp.cnt;
        ref();
    }
    smartptr<T> & operator =(const smartptr<T> &as)
    {
        if(origptr==as.origptr)
            return *this;
        deref();
        origptr=as.origptr;
        cnt=as.cnt;;
        ref();
        return *this;
    }
    void ref(){
        if(origptr){
            if(cnt)
                (*cnt)++;
            else
                { cnt=new int(1);
                }
        }
    }
    void deref(){
        if(origptr){
           (*cnt)--;
            if(*cnt==0)
            {
                delete origptr;
                origptr=NULL;
                delete cnt;
                cout<<"delete\n";
            }
        }
    }
    ~smartptr(){
        deref();
    }
};

int main(){
    smartptr<int> sptr(new int);
    smartptr<int> sptr2=sptr;
   // smartptr<int> t1(new int);
    //smartptr<int> t2(new int);
    sptr2=smartptr<int>(new int );
    smartptr<int> sp;
    sp=smartptr<int>(new int);
    sptr2=sptr;
    sp=sptr;

}

