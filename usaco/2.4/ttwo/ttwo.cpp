/*
ID:haoziyi1
PROG:ttwo
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<cstring>
using namespace std;
ifstream fin("ttwo.in");
ofstream fout("ttwo.out");
bool visit[10][10][4][2]={false};
char forest[10][11];
bool valid(int i,int j)
{
    return i>=0&&i<10&&j>=0&&j<10&&forest[i][j]!='*';
}
void step(int &i,int &j,int &dir)
{
    switch(dir){
        case 0:
        if(valid(i-1,j))
            i--;
        else
            dir++;
        break;
        case 1:
        if(valid(i,j+1))
            j++;
        else
            dir++;
        break;
        case 2:
        if(valid(i+1,j))
            i++;
        else
            dir++;
        break;
        case 3:
        if(valid(i,j-1))
            j--;
        else
            dir=0;
        break;
    }
}
int main(){
    int fi,fj,fd=0;
    int ci,cj,cd=0;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            fin>>forest[i][j];
            if(forest[i][j]=='F')
                fi=i,fj=j;
            else if(forest[i][j]=='C')
                ci=i,cj=j;
        }
    }
    int t=0;
    bool hascommon=false;
    int fc=-1,cc=-1;
    bool canfind=true;
    while(1)
    {
        if(fc==-1&&visit[fi][fj][fd][0])
        {
            // we have a circle.
            fc=t-visit[fi][fj][fd][0];
        }
        if(cc==-1&&visit[ci][cj][cd][1])
            cc=t-visit[ci][cj][cd][1];
        for(int i=0;i<4;i++)
			if(visit[fi][fj][i][1]||visit[ci][cj][i][0]){
				hascommon=true;
				break;
			}
        if(fi==ci&&fj==cj)
            break;
        if(fc!=-1&&cc!=-1)
        {
            if(fc==cc||!hascommon)
            {
                canfind=false;
                break;
            }

        }
        visit[fi][fj][fd][0]=1;
        visit[ci][cj][cd][1]=1;
        t++;
        step(fi,fj,fd);
        step(ci,cj,cd);
    }
    if(canfind)
        fout<<t<<endl;
    else
        fout<<0<<endl;
}

