/*
Auther:haozy
Problem:11.8
Language:C++
Description:get rank of number in a stream
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
//we can use a BST to implement it with a size field.
struct bst{
    bst *left,*right;
    int val;
    int size;
    bst():left(0),right(0),size(0){}
};
bst nd[1000];
int mid=0;
struct solution{
    bst *root;
    solution():root(0){}
    void track(int x)
    {
        if(root==NULL)
        {
            root=&nd[mid++];
            root->val=x;
            root->size=1;
            return;
        }
        bst *tmp=root;
        bst *pre=root;
        while(tmp){
            tmp->size++;
            pre=tmp;
            if(x<=tmp->val)
                tmp=tmp->left;
            else
                tmp=tmp->right;
        }
        tmp=&nd[mid++];
        tmp->val=x;
        tmp->size=1;
        if(x<=pre->val)
        {
            pre->left=tmp;
        }
        else
            pre->right=tmp;


        
    }
    int size(bst *rt)
    {
        if(rt==NULL)
            return 0;
        return rt->size;
    }
    int getRankOfNumber(int x)
    {
        bst *tmp=root;
        int pre=0;
        while(tmp){
            if(tmp->val==x)
               return pre+size(tmp->left);
            else if(tmp->val>x)
                tmp=tmp->left;
            else{
                pre+=size(tmp->left)+1;
                tmp=tmp->right;
            }
        }
        return -1;
    }
    void inorder()
    {
        inorder(root);
    }
    void inorder(bst *rt)
    {
        if(rt==NULL)
            return;
        inorder(rt->left);
        cout<<rt->val<<' ';
        inorder(rt->right);
    }
};
int main(){
    int n=20;
    solution sol;
    for(int i=0;i<n;i++){
        sol.track(rand()%20);
    }
    sol.inorder();
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<sol.getRankOfNumber(i)<<' ';
    }
    cout<<endl;

}

