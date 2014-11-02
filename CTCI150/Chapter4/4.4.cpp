/*
Auther:haozy
Problem:4.4
Language:C++
Description:create a linked list of all the nodes at each depth
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include<list>
#include"../struct.h"
using namespace std;
vector<list<bnode *> > tolist(bnode *rt)
{
    //we can use the list to mimic a queue.
    if(rt==NULL)
        return vector<list<bnode*> >();
    list<bnode *> fst;
    fst.push_back(rt);
    vector<list<bnode *> > ret;
    ret.push_back(fst);
    list<bnode *> *last=&ret[ret.size()-1];
    while(1)
    {
        list<bnode *> nxt;
        for(list<bnode *>::iterator iter=last->begin();iter!=last->end();++iter)
        {
            if((*iter)->left)
                nxt.push_back((*iter)->left);
            if((*iter)->right)
                nxt.push_back((*iter)->right);
        }
        if(nxt.size()==0)
        {
            break;
        }
        ret.push_back(nxt);
        last=&ret[ret.size()-1];
    }
    return ret;
}

int main(){
    bnode nd[7];
    for(int i=0;i<7;i++)
    {
        nd[i].val=i;
        nd[i].right=0;
        nd[i].left=0;
    }
    for(int i=0;i<3;i++)
    {
        nd[i].left=nd+2*i+1;
        nd[i].right=nd+2*i+2;
    }
    vector<list<bnode *> > rt=tolist(nd);
    for(int i=0;i<rt.size();i++)
    {
        for(list<bnode *>::iterator iter=rt[i].begin();iter!=rt[i].end();++iter)
        {
            cout<<(*iter)->val<<' ';
        }
        cout<<endl;
    }
}

