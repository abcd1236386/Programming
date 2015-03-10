/*
Auther:haozy
Problem:3.4
Language:C++
Description:use stack solve Hanoi Tower
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
stack<int> * pa=NULL,*pb=NULL,*pc=NULL;
char label(stack<int> *p)
{
    if(p==pa)
        return 'a';
    else if(p==pb)
        return 'b';
    else
        return 'c';
}
void Hanoi(stack<int> &a,stack<int> &b,stack<int> &c,int n)
{
    //from a to c, use b
    
    if(n==1)
    {
        cout<<"move "<<a.top()<<" from "<<label(&a)<<" to "<<label(&c)<<" use "<<label(&b)<<endl;
        c.push(a.top());
        a.pop();

    }
    else
    {
        Hanoi(a,c,b,n-1);
        cout<<"move "<<a.top()<<" from "<<label(&a)<<" to "<<label(&c)<<" use "<<label(&b)<<endl;
        c.push(a.top());
        a.pop();
        Hanoi(b,a,c,n-1);
    }
}
int main(){
    stack<int> a,b,c;
    pa=&a;
    pb=&b;
    pc=&c;
    a.push(3);
    a.push(2);
    a.push(1);
    Hanoi(a,b,c,3);
    while(!c.empty())
    {
        cout<<c.top()<<endl;
        c.pop();
    }
}

