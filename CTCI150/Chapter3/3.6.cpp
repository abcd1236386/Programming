/*
Auther:haozy
Problem:3.6
Language:C++
Description:sort a stack using only one extra stack
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include<stack>

using namespace std;
void sortStack(stack<int> &stk)
{
    if(stk.size()<2)
        return;
    stack<int> tmp; //only use this tmp as extra buffer.
    //biggest one on top.
    //fist ,find the biggest one.
    int big=stk.top();stk.pop();
    while(!stk.empty())
    {
        if(stk.top()>big)
        {
            tmp.push(big);
            big=stk.top();
        }
        else
            tmp.push(stk.top());
        stk.pop();
    }
    while(!tmp.empty()){
        stk.push(tmp.top());
        tmp.pop();
    }
    sortStack(stk);
    stk.push(big);
}
int sortStack_Iterator(stack<int> &stk)//this is select sort.
{
    int cnt=0;
    stack<int> tmp;
    int sorted=0;
    while(sorted<stk.size())
    {
        int sm=stk.top();stk.pop();cnt++;
        while(stk.size()>sorted)
        {
            if(stk.top()<sm)
            {
                tmp.push(sm);cnt++;
                sm=stk.top();
            }
            else 
                tmp.push(stk.top()),cnt++;
            stk.pop();cnt++;
        }
        //we finded the smallest one.
        stk.push(sm);cnt++;
        sorted++;
        while(!tmp.empty()){
            stk.push(tmp.top());
            tmp.pop();
            cnt+=2;
        }
    }
    return cnt;

}
int sortStack_Insert(stack<int> &stk)
{
    int cnt=0;
    stack<int> tmp;
    while(!stk.empty())
    {
        tmp.push(stk.top());
        stk.pop();
        cnt+=2;
    }
    //
    while(!tmp.empty())
    {
        int cur=tmp.top();tmp.pop();cnt++;
        while(!stk.empty()&&stk.top()>cur){
            tmp.push(stk.top());
            stk.pop();
            cnt+=2;
        }
        stk.push(cur);cnt++;
    }
    return cnt;
}
int sortStack_Quick(stack<int> &stk,bool asending=true)
{
    if(stk.size()<=1)
        return 0;
    stack<int> ls,gt;
    int cnt=0;
    int p=stk.top();stk.pop();cnt++;
    while(!stk.empty())
    {
        if(stk.top()<p)
            ls.push(stk.top());
        else
            gt.push(stk.top());
        stk.pop();
        cnt+=2;
    }
    cnt+=sortStack_Quick(ls,!asending);
    cnt+=sortStack_Quick(gt,!asending);
    stack<int> *f,*s;
    if(asending)
        f=&ls,s=&gt;
    else
        f=&gt,s=&ls;
    while(!f->empty())
    {
        stk.push(f->top());
        f->pop();
        cnt+=2;
    }
    stk.push(p);cnt++;
    while(!s->empty())
    {
        stk.push(s->top());
        s->pop();
        cnt+=2;
    }
    return cnt;
}
int main(){
    stack<int> a,b,c;
    for(int i=0;i<20;i++)
    {
        int t=rand()%10;
        a.push(t);
        b.push(t);
        c.push(t);
    }
    cout<<sortStack_Quick(a)<<' '<<sortStack_Iterator(b)<<" vs "<<sortStack_Insert(c)<<endl;
    while(!a.empty()){
        cout<<a.top()<<' '<<b.top()<<' '<<c.top()<<endl;
        a.pop();b.pop();c.pop();
    }
}

