/*
Auther:haozy
Problem:4.6
Language:C++
Description:implement successor of BST
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
struct bstn{
    bstn*left,*right,*parent;
    int val;
    bstn(){
        left=right=parent=0;
    }
};
bstn *successor(bstn* nd)
{
    if(nd==NULL)
        return NULL;
    if(nd->right!=NULL)
    {
        bstn*tp=nd->right;
        while(tp->left)
            tp=tp->left;
        return tp;
    }
    //no right child. 
    bstn* tp=nd->parent;
    while(tp!=NULL&&nd==tp->right)
    {
        nd=tp;
        tp=tp->parent;
    }
    return tp;
}
int main(){
    
    bstn nd[7];
    for(int i=0;i<7;i++)
    {
        nd[i].val=i;
        nd[i].right=0;
        nd[i].left=0;
    }
    bstn *rt=nd+3;
    nd[3].left=nd+1;
    nd[3].right=nd+5;
    nd[1].left=nd+0;
    nd[1].right=nd+2;
    nd[5].left=nd+4;
    nd[5].right=nd+6;
    nd[0].parent=nd[2].parent=nd+1;
    nd[4].parent=nd[6].parent=nd+5;
    nd[1].parent=nd[5].parent=nd+3;
    rt=nd;
    do{
        cout<<rt->val<<' ';
        rt=successor(rt);
    }while(rt);

}

