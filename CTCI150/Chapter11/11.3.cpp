/*
Auther:haozy
Problem:11.3
Language:C++
Description:find a element in rotated sorted array
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
int rotatedArrayFind(int A[],int n,int x)
{
    //
    int l=0,r=n-1;
    while(l<=r){
        int m=(l+r)/2;
        if(A[m]==x)
            return m;
        else if(A[m]>A[l]) //the left side is sorted.
        {
            if(x>=A[l]&&x<A[m])//in left side
                r=m-1;
            else
                l=m+1;

        }
        else if(A[m]<A[l]) //right side is sorted
        {
            if(x>A[m]&&x<=A[r])
                l=m+1;
            else
                l=m-1;
        }
        else //a[m] is equal to l ,we don't know  anything . we have a little to know.
        {   //the a[l] and a[r] should be same or uniqe.if they are uniqe ,and a[m]==a[l],
            //then a[l..m] are all the same. so we shoudl search right.
            if(a[l]==a[r])// now we are really nothing to know. it can be in any side.
                l++;
            else//search right
                l=m+1;

        }
    }
    return -1;

}

int main(){
    int a[5]={3,4,5,1,2};
    for(int i=0;i<=6;i++)
        cout<<rotatedArrayFind(a,5,i)<<endl;
}

