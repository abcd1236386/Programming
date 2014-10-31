/*
Auther:haozy
Problem:2.7
Language:C++
Description:list palindrome
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include"struct.h"
using namespace std;
//first method ,we can use a vector to convert list to vector.
//second method, we can use another list ,revsre it ,and will compare with the original one.
//third we can use a stack to save the first half of the node.
//fourth,we can use a recursion edition of the same idea of the third one.
bool ispalindrome(list *ls,int len,list *&next)
{
    if(ls==NULL)
        return true;
    if(len==0||len==1)
    {
       if(len==0)
           next=ls;
       else
           next=ls->next;
       return true;
    }
    bool r=ispalindrome(ls->next,len-2,next);
    r=r&&ls->val==next->val;
    next=next->next;
    return r;
}
int main(){
    list nd[10];
    for(int i=0;i<5;i++)
    {
        nd[i].val=nd[9-i].val=i;
        nd[i].next=nd+i+1;
        nd[i+5].next=nd+5+i+1;
    }
    nd[9].next=0;
    list *nx=NULL;
    nx=nd;
    while(nx){
        cout<<nx->val<<' ';
        nx=nx->next;
    }
    cout<<endl;
    cout<<ispalindrome(nd,10,nx)<<endl;
}

