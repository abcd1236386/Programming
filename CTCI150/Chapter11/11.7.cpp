/*
Auther:haozy
Problem:11.7
Language:C++
Description:
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
//longest increasing subsequence of pairs.
struct htwt{
    int h,w;
    bool operator <(const htwt& hw) const{
        return h<hw.h;
    }
};
int LIS(vector<htwt> &v) //O(n^2)
{
    sort(v.begin(),v.end());
    //
    vector<int> len(v.size(),1);
    int mxlen=1;
    for(int i=1;i<v.size();i++)
    {
        int cm=-1;
        for(int j=0;j<i;j++)
        {
            if(v[i].h>v[j].h&&v[i].w>v[j].w&&cm<len[j])
                cm=len[j];
        }
        len[i]=cm+1;
        if(len[i]>mxlen)
            mxlen=len[i];
    }
    return mxlen;
}
// can we use a nlogn?
//if we like lis of inteager ,we can have a nlogn ,but what if a pair of number?
//we can logn time to find the place to put v[i] ,but how to update the ,if we can proof that if v[len]<v[i]
//we can replace without problem , but if v[len] not less than v[i] .which should we use ,does it matter which
//one we chose ? (2,3) (8,4) vs (4,6) ?should we use (8,4) or (4,6) if we have another (9,5) and (5,7) .both
//of them can be the better one. so this method does't work.
int main(){

}

