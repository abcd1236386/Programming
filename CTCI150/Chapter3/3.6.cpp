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
void sortStack_Iterator(stack<int> &stk)
{
    stack<int> tmp;
    int sorted=0;
    while(sorted<stk.size())
    {
        int sm=stk.top();stk.pop();
        while(stk.size()>sorted)
        {
            if(stk.top()<sm)
            {
                tmp.push(sm);
                sm=stk.top();
            }
            else 
                tmp.push(stk.top());
            stk.pop();
        }
        //we finded the smallest one.
        stk.push(sm);
        sorted++;
        while(!tmp.empty()){
            stk.push(tmp.top());
            tmp.pop();
        }
    }

}
int main(){
    stack<int> a,b;
    for(int i=0;i<20;i++)
    {
        int t=rand()%10;
        a.push(t);
        b.push(t);
    }
    sortStack(a);
    sortStack_Iterator(b);
    while(!a.empty()){
        cout<<a.top()<<' '<<b.top()<<endl;
        a.pop();b.pop();
    }
}

