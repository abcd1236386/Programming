/*
ID:haoziyi1
PROG:holstein
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
#include<queue>
using namespace std;
ifstream fin("holstein.in");
ofstream fout("holstein.out");
int V,G;
int feeds[15][25];
struct nd{
    int buf[25];
    vector<int> lasti;
    nd(){
    }
    nd genNext(int i){
        nd temp=*this;
        temp.lasti.push_back(i);
        for(int j=0;j<V;j++){
            temp.buf[j]-=feeds[i][j];
        }
        return temp;
    }
    bool OK(){
        for(int j=0;j<V;j++)
            if(buf[j]>0)
                return false;
        return true;
    }
};
int main(){
  fin>>V;
  queue<nd> Q;
  nd sn;
  for(int i=0;i<V;i++)
      fin>>sn.buf[i];
  fin>>G;
  for(int i=0;i<G;i++)
    {
        for(int j=0;j<V;j++)
        {
            fin>>feeds[i][j];
        }
    }
  //we do a bfs.
  Q.push(sn);
  while(!Q.empty())
  {
      nd t=Q.front();Q.pop();
      if(t.OK())
      {
          fout<<t.lasti.size()<<' ';
          for(int i=0;i<t.lasti.size();i++)
          {
              fout<<t.lasti[i]+1;
              if(i==t.lasti.size()-1)
                  fout<<'\n';
              else
                  fout<<' ';
          }

          break;
      }
      //else.
      int start;
      if(t.lasti.size()==0)
          start=0;
      else
          start=t.lasti[t.lasti.size()-1]+1;
      for(int i=start;i<G;i++)
      {
          Q.push(t.genNext(i));
      }
  }
  
}

