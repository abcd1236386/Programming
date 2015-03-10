/*
Auther:haozy
Problem:3.1
Language:C++
Description:sigle array to implement 3 stak
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
const int maxn=30;
struct stack3{
    int a[maxn];
    int id1,id2,id3;
    int s2start;
    stack3(){
        id1=0;
        id3=maxn-1;
        id2=s2start=maxn/3;
    }
    bool full()
    {
        return !(id1<s2start||id2<id3);
    }
    void push(int id,int x)
    {
        if(full()){
            cout<<"full now,state:";
            cout<<id1<<' '<<s2start<<' '<<id2<<' '<<id3<<endl;
            return;
        }
        if(id==1)
        {
            if(id1<s2start){
                a[id1++]=x;
            }
            else//reassign
            {
                int rem=id3-id2+1;// all empty slot
                int mv=max(1,rem/3);
                int k=id2-1+mv;
                int i=id2-1;
                while(i>=s2start)
                    a[k--]=a[i--];
                s2start+=mv;
                id2+=mv;
                a[id1++]=x;
                cout<<"move 2 right:"<<mv<<endl;
            }
        }else if(id==2||id==3)
        {
            if(id2<id3){
            }
            else// reassign
            {
                int rem=s2start-id1;
                int mv=max(1,rem*2/3);
                int k=s2start-mv;
                int i=s2start;
                while(i<id2){
                    a[k++]=a[i++];
                }
                s2start-=mv;
                id2-=mv;
                cout<<"move 2 left:"<<mv<<endl;
            }
            if(id==2)
                a[id2++]=x;
            else
                a[id3--]=x;
        }
    }
    int  pop(int id)
    {
        if(id==1&&id1>0)
            return a[--id1];
        if(id==2&&id2>s2start)
            return a[--id2];
         if(id==3&&id3<maxn-1)
             return a[++id3];
    }
};
int main(){
    stack3 stk;
    for(int i=0;i<maxn+5;i++)
    {
        int id=rand()%3+1;
        stk.push(id,i);
    }
    for(int i=0;i<maxn+5;i++)
    {
        int id=rand()%3+1;
        cout<<stk.pop(id)<<' ';

    }
}

