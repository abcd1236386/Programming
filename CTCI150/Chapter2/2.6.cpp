/*
Auther:haozy
Problem:2.6
Language:C++
Description:circular link list to find the beginning of the loop
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
//use two pointer .p1,p2. p1 move one step every action and p2 move two. let us say that the beginning
// of the list and the begingnning of the circle's distance is x, so when p1 move to the beginning of 
//the circle ,the distanc between p2 and p1 is y, so we hanve x=y+nk, where k is the length of the circle.
//so when they meet in the circle .p2 must have move forward (k-y) step. so the meet point must be y
//(k-(k-y)=y)node befor the beginning node of the circle. as we have x=y+nk. so if we move p2 to beginning,
// and move one step each. so we can see that it must meet at the beginning of the circle. so we can return
// it .
list * findbeginning(list * ls)
{
    //if it has no circle return null.
    list *p1,*p2;
    p1=p2=ls;
    do{
        p1=p1->next;
        p2=p2->next;
        if(p2)
            p2=p2->next;
    }while(p1!=p2&&p2!=NULL);
    if(p2==NULL)
        return NULL;
    p2=ls;
    while(p1!=p2){
        p1=p1->next;
        p2=p2->next;
    }
    return p1;
        
}
int main(){
    list nd[15];
    for(int i=0;i<15;i++)
    {
        nd[i].val=i;
        nd[i].next=nd+i+1;
    }
    nd[14].next=0;
    list *p=findbeginning(nd);
    if(p!=NULL)
        cout<<"something wrong\n";
    else 
        cout<<"list no circle\n";
    nd[14].next=nd+4;
    p=findbeginning(nd);
    cout<<"should be 4,output:";
    cout<<p->val<<endl; //must be 4
    nd[14].next=nd+10;
    cout<<"should be 10,output:";
    p=findbeginning(nd);
    cout<<p->val<<endl;//must be 10;
}

