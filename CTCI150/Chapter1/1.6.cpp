/*
Auther:haozy
Problem:1.6
Language:C++
Description:rotate 90 of matrix
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
void rotate90(vector<vector<int> > &mat)
{
    int N=mat.size();
    int si=0,sj=0;
    int len=N-1;
    while(len>0){
    for(int i=0;i<len;i++)
    {
        //(si,sj+i)->(si+i,sj+len)->(si+len,sj+len-i)->(si+len-i,sj);
        int tmp=mat[si+len-i][sj];
        mat[si+len-i][sj]=mat[si+len][sj+len-i];
        mat[si+len][sj+len-i]=mat[si+i][sj+len];
        mat[si+i][sj+len]=mat[si][sj+i];
        mat[si][sj+i]=tmp;
    }
    len-=2;
    si++;
    sj++;
    }
}
int main(){
    vector<vector<int> > mat;
    for(int i=0;i<5;i++)
    {
        vector<int > v;
        for(int j=0;j<5;j++)
            v.push_back(i*5+j);
        mat.push_back(v);
    }
    rotate90(mat);
    for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
                cout<<mat[i][j]<<' ';
            cout<<endl;
        }

}

