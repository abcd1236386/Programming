/*
Auther:haozy
Problem:4.5
Language:C++
Description:check a binary tree is a binary search tree
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include<climits>
#include"../struct.h"
using namespace std;
bool isBST(bnode *rt,int &mx,int &mi)
{
    if(rt==NULL)
    {
        mx=INT_MIN;
        mi=INT_MAX;
       return true;
    }
    if(!isBST(rt->left,mx,mi)||rt->val<mx)
        return false;
    int rmx,rmi;
    if(!isBST(rt->right,rmx,rmi)||rt->val>rmi)
        return false;
    //this sub tree is valid.
    if(mx<max(rt->val,rmx))
        mx=max(rt->val,rmx);
    if(mi>min(rt->val,rmi))
        mi=min(rt->val,rmi);
    return true;
}
bool isBST(bnode *rt,bnode *&pre)
{
    //we do a inorder traversal, if so rt must >=pre.if not ,we return false.
    if(rt==NULL)
        return true;
    if(!isBST(rt->left,pre))
        return false;
    if(pre!=NULL&&rt->val<pre->val)
        return false;
    pre=rt;
    return isBST(rt->right,pre);
}
bool isBST_def(bnode *rt,int mi,int mx)
{
    if(rt==NULL)
        return true;
    if(rt->val<=mi||rt->val>mx)
        return false;
    return isBST_def(rt->left,mi,rt->val)&&
        isBST_def(rt->right,rt->val,mx);
}
int main(){
    
    bnode nd[7];
    for(int i=0;i<7;i++)
    {
        nd[i].val=i;
        nd[i].right=0;
        nd[i].left=0;
    }
    bnode *rt=nd+3;
    nd[3].left=nd+1;
    nd[3].right=nd+5;
    nd[1].left=nd+0;
    nd[1].right=nd+2;
    nd[5].left=nd+4;
    nd[6].right=nd+6;
    int mx,mi;bnode *pre=NULL;
    cout<<isBST(rt,mx,mi)<<" souble be 1\n";
    cout<<isBST(rt,pre)<<" souble be 1\n";
    cout<<isBST_def(rt,INT_MIN,INT_MAX)<<" souble be 1\n";
    nd[2].val=10;pre=NULL;
    cout<<isBST(rt,mx,mi)<<" should be 0\n";
    cout<<isBST(rt,pre)<<" should be 0\n";
    cout<<isBST_def(rt,INT_MIN,INT_MAX)<<" should be 0\n";

    nd[2].val=2;
    nd[4].val=2;pre=NULL;
    cout<<isBST(rt,mx,mi)<<" souble be 0\n";
    cout<<isBST(rt,pre)<<" souble be 0\n";
    cout<<isBST_def(rt,INT_MIN,INT_MAX)<<" souble be 0\n";
}

