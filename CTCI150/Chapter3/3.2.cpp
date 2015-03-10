/*
Auther:haozy
Problem:3.2
Language:C++
Description:stack with min function ,O(1) time
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
struct stackMin{
    vector<int> buf;
    vector<int> minbuf;
    int tp;
    int mtp;
    stackMin(){
        tp=-1;
        mtp=-1;
    }
    void push(int x)
    {
        tp++;
        if(tp==buf.size())
        {
            buf.push_back(x);
        }
        else
            buf[tp]=x;
        if(mtp==-1||buf[tp]<=min())
        {
            ++mtp;
            if(mtp==minbuf.size())
                minbuf.push_back(x);
            else
                minbuf[mtp]=x;
        }

    }
    bool empty(){
        return tp==-1;
    }
    int pop()
    {
        if(empty())
            return -1;
        if(top()==min())
            mtp--;
        return buf[tp--];
    }
    int min(){
        return minbuf[mtp];
    }
    int top(){
        return buf[tp];
    }
};
int main(){
    stackMin sm;
    for(int i=0;i<20;i++)
    {
        int ac=rand()%2;
        if(ac&&!sm.empty())
        {
            sm.pop();
            cout<<"pop"<<endl;
        }
        else{
            int t=rand()%10;
            sm.push(t);
            cout<<"push "<<t<<endl;
        }
        if(!sm.empty())
            cout<<sm.min()<<' '<<endl;
    }
}

