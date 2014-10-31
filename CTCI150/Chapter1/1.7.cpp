/*
Auther:haozy
Problem:1.7
Language:C++
Description:set entire row&column 0 if element is 0
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
void change(vector<vector<int> > &mat)
{
    int m=mat.size();
    int n=mat[0].size();
    //use O(1) space complex
    bool frow=false;
    bool fcol=false;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mat[i][j]==0)
            {
                mat[0][j]=0;
                mat[i][0]=0;
                if(i==0)
                    frow=true;
                if(j==0)
                    fcol=true;
               }
        }
    }
    for(int i=1;i<n;i++)
        if(mat[0][i]==0)
            for(int j=0;j<m;j++)
                mat[j][i]=0;
    
    for(int i=1;i<m;i++)
        if(mat[i][0]==0)
            for(int j=0;j<n;j++)
                mat[i][j]=0;
    //handle first line 
    if(frow)
        for(int i=0;i<n;i++)
            mat[0][i]=0;
    if(fcol)
        for(int i=0;i<m;i++)
            mat[i][0]=0;

}
void change_no_extra_space(vector<vector<int> > & mat)
{
    //four state ,(0,0)(0,1),(1,0),(1,1)
    //we first 
    if(mat[0][0]==0)//first state
    {
        //handle normally.
    }
    else{
        for(int i=0;i<mat.size();i++)
            if(mat[i][0]==0)
                mat[0][0]=0;
        for(int i=0;i<mat[0].size();i++)
            if(mat[0][i]==0)
                mat[0][0]=0;
        if(mat[0][0]!=0)//last state.
        {
            //handle normally.
        }
        else //the three case ,we can hanle easily.
        {
            mat[0][0]=3;
            for(int i=0;i<mat.size();i++)
                if(mat[i]][0]==0)
                {
                    mat[0][0]-=1;
                    break;
                }
            for(int i=0;i<mat[0].size();i++)
            {
                if(mat[0][i]==0)
                {
                    mat[0][0]-=2;
                    break;
                }
            }
            //handle normally.

            //after hanle
            if(mat[0][0]==0)//first case
            {

            }
            else if(mat[0][0]==1)//second case.change entire first colomn
            {
            }
            else//third case ,change entire first row to 0.
            {
            }
        }
    }
}
int main(){
    int n=10;
    vector<vector<int> > mat;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        v.clear();
        for(int j=0;j<n;j++)
        {
             v.push_back(rand()%10);
             cout<<v[j]<<' ';
        }
        mat.push_back(v);
        cout<<endl;
    }
    change(mat);
    cout<<"after chnage\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<mat[i][j]<<' ';
        cout<<endl;
    }

}

