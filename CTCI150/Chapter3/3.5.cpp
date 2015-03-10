/*
Auther:haozy
Problem:3.5
Language:C++
Description:use two stack implement a queue
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
struct myqueue{
    stack<int> in;
    stack<int> out;
    void enqueue(int x){
        in.push(x);
    }
    int dequeue(){
        if(out.empty())
        {
            while(!in.empty())
            {
                out.push(in.top());
                in.pop();
            }

        }
        int t=out.top();
        out.pop();
        return t;
    }

};
int main(){

}

