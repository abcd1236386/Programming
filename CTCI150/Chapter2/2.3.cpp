/*
Auther:haozy
Problem:2.3
Language:C++
Description:remove a middle node of link list
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
struct list {
    list *next;
    int val;
};
void remove(list * p)
{
    if(p==NULL||p->next==NULL)
        return ;
    list *n=p->next;
    p->next=n->next;
    p->val=n->val;
}
int main(){
    list nd[5];
    for(int i=0;i<5;i++)
        {
            nd[i].next=nd+i+1;
            nd[i].val=i;
        }
    nd[4].next=0;
    remove(nd+2);
    list *t=nd;
    while(t){
        cout<<t->val<<' ';
        t=t->next;
    }
    cout<<endl;

}

