/*
ID:haoziyi1
PROG:preface
LANG:C++
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
ifstream fin("preface.in");
ofstream fout("preface.out");
int cnt[7]={0};
void count(int x)
{
    //we have 
    //1000 M
    //900 CM
    //500 D
    //400 CD
    //100 C
    //90 XC
    //50 L
    //40 XL
    //10 X
    //9 IX
    //5 V
    //4 IV
    //1 I
    //I V X L C D M
    //0 1 2 3 4 5 6
    int tominus[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    int tid=0;
    while(x){
        while(x<tominus[tid])
            tid++;
        x-=tominus[tid];
        switch(tominus[tid])
        {
            case 1000:
                cnt[6]++;
                break;
            case 900:
                cnt[6]++;
                cnt[4]++;
                break;
            case 500:
                cnt[5]++;
                break;
            case 400:
                cnt[5]++;
                cnt[4]++;
                break;
            case 100:
                cnt[4]++;
                break;
            case 90: cnt[4]++,cnt[2]++;
            break;
            case 50: cnt[3]++;break;
            case 40: cnt[3]++,cnt[2]++;break;
            case 10: cnt[2]++;break;
            case 9: cnt[2]++,cnt[0]++;break;
            case 5:cnt[1]++;break;
            case 4:cnt[1]++,cnt[0]++;break;
            case 1:cnt[0]++;break;
        }
    }
}
int main(){
    int N;
    fin>>N;
    for(int i=1;i<=N;i++)
    {
        count(i);
    }
    char ch[8]={"IVXLCDM"};
    for(int i=6;i>=0;i--)
    {
        if(cnt[i]!=0)
        {
            for(int j=0;j<=i;j++)
            {
                fout<<ch[j]<<' '<<cnt[j]<<'\n';
            }
            break;
        }
    }
}

