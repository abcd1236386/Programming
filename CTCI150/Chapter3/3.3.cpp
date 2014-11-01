/*
Auther:haozy
Problem:3.3
Language:C++
Description:mimics sets of stack to implement one
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
int maxn=5;
struct SetOfStacks{
    vector<stack<int> > stks;
    void push(int x)
    {
        int last=stks.size()-1;
        if(stks[last].size()==maxn)
        {
            stks.push_back(stack<int>());
            last++;
        }
        stks[last].push(x);
    }
    int pop(){
        int last=stks.size()-1;
        while(last>=0&&stks[last].empty())
            last--;
        int t=stks[last].top();stks[last].pop();
        return t;
    }
    int popAt(int idx)
    {
        if(!stks[idx].empty())
        {
            t=stks[idx].top();
            stks[idx].pop();
            return t;
        }
    }
};
int main(){

}

