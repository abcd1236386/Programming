/*
Auther:haozy
Problem:4.3
Language:C++
Description:convert sorted array to bst with minimal height
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
bnode nd[1000];
int nid=0;
bnode *newNode()
{
    return &nd[nid++];
}
bnode *Convert(int a[],int n)
{
    if(n==0)
        return NULL;
    int md=n/2;
    bnode *root=newNode();
    root->val=a[md];
    root->left=Convert(a,md);
    root->right=Convert(a+md+1,n-md-1);
    return root;
}
void inorder(bnode *rt)
{
    if(rt==NULL)
        return;
    inorder(rt->left);
    cout<<rt->val<<' ';
    inorder(rt->right);
}
int main(){
    int a[15];
    for(int i=0;i<15;i++)
        a[i]=i;
    bnode *rt=Convert(a,15);
    inorder(rt);
    cout<<endl;
}

