/*
Auther:haozy
Problem:17.6
Language:C++
Description:given a array of integers write a method to find indices m and n such that if you sorted elements m through n whole array will be sorted
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
//for a array of lenth n, [0,n) will be the right scope. so we should find that [0,m) that are all in their 
//place ,and (n',n) that is already in their place two.
//so how should we do this ? so if we have another sorted array ,we should check if a[i]==b[i] ,the the first //i will become m,and the last i will become n' so it is O(nlgn).and O(n) space.

//the other idea is that we can have a in-variant that if max(left)<min(middle) and max(middle)<min(right)
//and all [0,m) should be sorted. so we first find the sorted left and right side.
//say that [0,i) is sorted. and(j,n) is sorted .so middle is [i,j] and we should find max(mid)and min(mid)
// then we form i to 0,we do that if a[i] is >min(mid) it sould be in the mid, we do the same of right side
// as well, so when a[i]<=min(mid) ,all the left will be less than or equal to mid.
//and for special case ,wehn i>=j ,the array will be sorted already.
//this method will be O(n) time, and O(1) additional space.
pair<int,int> findmiddlescope(int a[],int n)
{
    int i=0,j=n-1;
    while(i<n-1&&a[i+1]>=a[i])
        i++;
    while(j>0&&a[j-1]<=a[j])
        j--;
    //a[i] is less than a[i-1] and a[j]>a[j+1]
    if(i==n-1)
        return make_pair<int,int>(0,0);
    //a[i..j] is middle.
    //we should attention that ,we should use the last of left ,and first or right to be mid.
    //such that the middle contain the max of left ,and min of right .so we to shrink the left 
    //and right , the max of right won't affacet the right and the min of right will not affact the 
    //left size.
    int mi=a[i],ma=a[i];
    for(int k=i+1;k<=j;k++)
        if(mi>a[k])
            mi=a[k];
        else if(ma<a[k])
            ma=a[k];
    while(i>0){
        if(a[i-1]>mi){
            i--;
        }
        else
            break;
    }
    while(j<n-1)
        if(a[j+1]<ma){
            j++;
        }
        else
            break;
    return make_pair<int,int>(i,j);
}
int main(){
    int a[5]={1,2,3,4,5};
    pair<int,int> pa;
    pa=findmiddlescope(a,5);
    cout<<pa.first<<' '<<pa.second<<endl;
    int b[5]={5,1,2,3,4};
    pa=findmiddlescope(b,5);
    cout<<pa.first<<' '<<pa.second<<endl;
    int c[5]={1,4,2,3,5};
    pa=findmiddlescope(c,5);
    cout<<pa.first<<' '<<pa.second<<endl;
    
}

