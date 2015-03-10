/*
Auther:haozy
Problem:2.1
Language:C++
Description:remove duplicates from linked list
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
void removeDup(list *ls)
{
    list *tmp=ls;
    while(tmp)
    {
        list *t2=tmp->next;
        list *pre=tmp;
        while(t2){
            if(t2->val==tmp->val)
            {
                pre->next=t2->next;
               // delete t2;
                t2=t2->next;
            }
            else
            {
                pre=t2;
                t2=t2->next;
            }
        }
        tmp=tmp->next;
    }
}
//we can use merge sort to sort the list ,and then we delete the duplicat.
//it will be O(nlgn) time complexity
list *merge(list *l1,list *l2)
{
    if(l1==NULL)
        return l2;
    else if(l2==NULL)
        return l1;
    list *h=NULL;
    list *t=NULL;
    while(l1&&l2){
        if(l1->val<l2->val)
        {
            if(t==NULL)
            {
                h=t=l1;
            }
            else{
                t->next=l1;
                t=l1;
            }
            l1=l1->next;
        }
        else{
            if(t==NULL)
            {
                h=t=l2;
            }
            else{
                t->next=l2;
                t=l2;
            }
            l2=l2->next;
        }
    }
    if(l1!=NULL)
        t->next=l1;
    if(l2!=NULL)
        t->next=l2;
    return h;
}
list * mergesort(list *ls)
{
    if(ls==NULL||ls->next==NULL)
        return ls;//nothing todo.
    //split list O(n)
    list *l1=NULL,*l2=NULL;
    l1=ls;
    list *t=ls->next;
    l2=ls;
    list *p=NULL;
    while(t){
        t=t->next;
        if(t){
            t=t->next;

            l2=l2->next;
        }

    }
    p=l2;
    l2=l2->next;
    p->next=NULL;
    l1=mergesort(l1);
    l2=mergesort(l2);
    return merge(l1,l2);

}
list* removeSortedDup(list * ls)
{
    ls=mergesort(ls);
    list *hd=ls;

    //sorted O(nlgn) ,remove can be done in O(n)
    while(ls){
        if(ls->next==NULL||ls->next->val!=ls->val)
            ls=ls->next;
        else{
            ls->next=ls->next->next;
        }
    }
    return hd;
}
list nd[100];
int main(){
    for(int i=0;i<20;i++)
    {
        nd[i].next=nd+i+1;
        nd[i].val=rand()%5;
    }
    nd[19].next=0;
    list *tmp=nd;
    while(tmp){
        cout<<tmp->val<<' ';
        tmp=tmp->next;
    }
    cout<<endl;
    tmp= removeSortedDup(nd);
    
    while(tmp){
        cout<<tmp->val<<' ';
        tmp=tmp->next;
    }
    cout<<endl;

}

