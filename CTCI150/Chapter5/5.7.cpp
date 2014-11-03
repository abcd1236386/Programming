/*
Auther:haozy
Problem:5.7
Language:C++
Description:a arrary 0..n missing one number ,find it in O(n) time only use fetch the jth bit of A[i]
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
#include<ctime>
using namespace std;
class array{
    int a[100];
    int x;
public:
    void init(){
        srand(time(NULL));
        x=rand()%101;
        int j=0;
        for(int i=0;i<101;i++){
            if(x==i)
                continue;
            a[j++]=i;
        }
    }
    bool fetch(int i,int j)
    {
        return a[i]&(1<<j);
    }
    int get(){
        int c=0;
        int ai=0;
        int bi=0;
        while(ai<100||bi<=100){
            if(ai>=100||c<a[ai])
                c+=bi++;
            else
                c-=a[ai++];
        }
        return c;
    }
    int getXor(){
        //we xor all element and then xor 0...n ,so the missing element will be the result.
        int c=0;
        for(int i=0;i<100;i++){
            c^=i;
            c^=a[i];
        }
        c^=100;
        return c;
    }
    int getx(){
        return x;
    }
};

int main(){
    array A;
    A.init();
    cout<<A.get()<<' '<<A.getXor()<<' '<<A.getx()<<endl;
}

