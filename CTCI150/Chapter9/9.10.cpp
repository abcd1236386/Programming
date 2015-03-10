/*
Auther:haozy
Problem:9.10
Language:C++
Description:heighest boxes
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
//we can sorted the box, then we pick on ,and for each one bellow it ,we check if it can be put on it.
// so dp[i]=max(dp[j],j<i)+1;
struct box{
    int w,h,d;
    bool operator<(const box &b) const{
        return w<b.w&&h<b.h&&d<b.d;
    }
};
int heightest(vector<box> & boxes)
{
    sort(boxes.begin();boxes.end());
    int dp[boxes.size()+1];
    memset(dp,0,sizeof(dp));
    for(int i=boxes.size()-1;i>=0;i--)
    {
        dp[i]=0;
        for(int j=i+1;j<boxes.size();j++)
        {
            if(boxes[i]<boxes[j]&&dp[i]<dp[j])
                dp[i]=dp[j];
        }
        dp[i]+=boxes[i].d;
    }
    return dp[0];
}
int main(){

}

