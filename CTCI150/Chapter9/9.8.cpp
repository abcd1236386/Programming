/*
Auther:haozy
Problem:9.8
Language:C++
Description: cents split
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
// we have cents of 25,10,5,1.
int cents[4]={25,10,5,1};
int method(int curi,int rem)
{
    if(rem==0)
        return 1;
    if(curi==4||rem<0)
        return 0;
    return method(curi+1,rem)+method(curi,rem-cents[curi]);
}
int method2(int curi,int rem)
{
    if(rem==0)
        return 1;
    if(curi==4||rem<0)
        return 0;
    int s=0;
    //at least select one.
    for(int i=curi;i<4;i++)
    {
        s+=method2(i,rem-cents[i]);
    }
    return s;
}
//also we can use dp to solve this problem.
//dp[i] means for num i we have method.
//so dp[i]=dp[i-1]+dp[i-5]+dp[i-10]+dp[i-25];
//but to keep unique, if we select i, the least must be i.
//so we can use dp[i,j] to indicate that at most is i ,that for j's method.
//so dp[i,j]=dp[i,j-i]+dp[i-1,j].
int method_dp(int rem)
{
    int dp[5][rem+1];
    memset(dp,0,sizeof(dp));
    int cents[4]={1,5,10,25};
    dp[0][0]=1;
    dp[1][0]=1;
    dp[2][0]=1;
    dp[3][0]=1;
    dp[4][0]=1;
    for(int i=1;i<=rem;i++)
    {
        for(int j=1;j<=4;j++)
        {
            dp[j][i]=dp[j-1][i];
            if(cents[j-1]<=i)
                dp[j][i]+=dp[j][i-cents[j-1]];
        }
    }
    return dp[4][rem];
}
int main(){
    cout<<method(0,100)<<endl;
    cout<<method2(0,100)<<endl;
    cout<<method_dp(100)<<endl;
}

