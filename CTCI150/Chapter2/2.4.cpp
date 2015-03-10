/*
Auther:haozy
Problem:2.4
Language:C++
Description:partition linked list
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
struct list{
    list *next;
    int val;
};
list *partition(list *ls,int x)
{
    list *h=NULL,*t=NULL;
    while(ls)
    {
        if(h==NULL)
        {
                h=t=ls;
                ls=ls->next;
        }
        else if(ls->val<x){
            list *tm=ls;
            ls=ls->next;
            tm->next=h;
            h=tm;
        }
        else{
            list *tm=ls;
            ls=ls->next;
            t->next=tm;
            t=tm;
        }
    }
    return h;
}
int main(){
    list nd[20];
    for(int i=0;i<20;i++){
        nd[i].val=rand()%10;
        nd[i].next=nd+i+1;
    }
    nd[19].next=0;
    list *p=partition(nd,5);
    while(p)
    {
        cout<<p->val<<endl;
        p=p->next;
    }
}

