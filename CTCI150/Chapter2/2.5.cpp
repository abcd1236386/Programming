/*
Auther:haozy
Problem:2.5
Language:C++
Description:add two numbers represented by link list
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
list nd[1000];
int nid=0;
list *allocate()
{
    return &nd[nid++];
}
list *add(list *l1,list *l2)
{
    int c=0;
    list *p=NULL;
    list *t=NULL;
    while(l1!=NULL||l2!=NULL||c!=0){
        int s=c;
        c=0;
        if(l1!=NULL)
        {
            s+=l1->val;
            l1=l1->next;
        }
        if(l2!=NULL){
            s+=l2->val;
            l2=l2->next;
        }
        if(s>=10)
        {
            s-=10;
            c=1;
        }
        //a new node.
        list *tm=allocate();
        tm->val=s;
        if(p==NULL)
        {
            p=t=tm;
        }
        else
        {
            t->next=tm;
            t=tm;
        }


    }
    return p;
}
list *reverse(list *ls)
{
    list *pre=0;
    list *cur=ls;
    list *tmp;
    while(cur){
        tmp=cur;
        cur=cur->next;
        tmp->next=pre;
        pre=tmp;
    }
    return pre;
}
list* add2(list *l1,list *l2){
    l1=reverse(l1);
    l2=reverse(l2);
    list *a=add(l1,l2);
    return reverse(a);
}
int main(){
    list *l1=allocate();
    l1->val=7;
    list *t=l1;
    t->next=allocate();
    t=t->next;
    t->val=1;

    t->next=allocate();
    t=t->next;
    t->val=6;
    t->next=NULL;
    list *l2=allocate();
    l2->val=5;
    t=l2;
    t->next=allocate();
    t=t->next;
    t->val=9;
    t->next=allocate();
    t=t->next;
    t->val=2;
    t->next=0;
    t=add(l1,l2);
    while(t){
        cout<<t->val<<endl;
        t=t->next;
    }
    cout<<"...\n";
    t=add2(l1,l2);
    while(t){
        cout<<t->val<<endl;
        t=t->next;
    }


}

