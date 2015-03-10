/*
Auther:haozy
Problem:4.7
Language:C++
Description:LCA in binary tree
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include"../struct.h"
using namespace std;
bool intree(bnode *rt,bnode *x)
{
    if(rt==NULL||x==NULL)
        return false;
     if(rt==x)
         return true;
     return intree(rt->left,x)||intree(rt->right,x);
}
bnode *lca(bnode *rt,bnode *p,bnode *q)
{
    if(!intree(rt,p)||!intree(rt,q))
        return NULL;
    return lca_r(rt,p,q);
}
bnode *lca_r(bnode *rt,bnode *p,bnode *q)
{
    if(rt==NULL)
        return NULL;
    if(root==p||root==q)
        return root;
    bnode *lf=lca_r(rt->left,p,q);
    bnode *ri=lca_r(rt->right,p,q);
    if(lf==NULL)
        return ri;
    else if(ri==NULL)
        return lf;
    else
        return root;
}
struct res{
    bnode *nd;
    bool ca;
    res(bnode *n,bool b)
    {
        nd=n;
        ca=b;
    }
};
res lca_2(bnode *rt,bnode *p,bnode *q)
{
    if(rt==NULL)
        return res(NULL,false);
    if(root==p&&root==q)
        return res(root,true);
    res rl=lca_2(rt->left,p,q);
    if(rl.ca)
        return rl;
    res rr=lca_2(rt->right,p,q);
    if(rr.ca)
        return rr;
    //non of them are common ancestor. so we have 
    if(rl.nd!=NULL&&rr.nd!=NULL)
        return res(root,true);
    else if(root==p||root==q)
    {
        bool ca=rl.nd!=NULL||rr.nd!=NULL;
        return res(root,ca);
    }
    else //at least one nd is null,
        return res(rl.nd?rl.nd:rr.nd,false);
}
int main(){

}
