/*
Auther:haozy
Problem:2.2
Language:C++
Description:kth to the last of linked list
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<cstring>
struct list{
    list*next;
    int val;
};
using namespace std;
list *theKth(list *ls,int k){
    list *t=ls;
    int c=0;
    while(c<k&&t){
            t=t->next;
            c++;
    }
    if(c<k){
        return NULL;
    }
    list *p=ls;
    while(t){
        t=t->next;
        p=p->next;
    }
    return p;
}
list nd[10];      
int main(){
    for(int i=0;i<9;i++){
        nd[i].val=i;
        nd[i].next=nd+i+1;
    }
    nd[9].val=9;
    nd[9].next=0;
    for(int k=1;k<20;k++){
        list *p=theKth(nd,k);
        if(p)
            cout<<p->val<<endl;
    }
}

