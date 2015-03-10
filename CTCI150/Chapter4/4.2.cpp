/*
Auther:haozy
Problem:4.2
Language:C++
Description:given a directed graph,find if have a route between two nodes
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
//we use a pairs to save the edges. node id unique 0...N.
const int N=10;
bool dfs(vector<vector<int> >& graph,vector<bool> &vst,int x,int y)
{
    if(x==y)
        return true;
    for(int i=0;i<graph[x].size();i++)
    {
        if(!vst[graph[x][i]])
        {
            vst[graph[x][i]]=true;
            if(dfs(graph,vst,graph[x][i],y))
                return true;
        }
    }
    return false;
}
bool have_route(vector<pair<int,int> > &edges,int x,int y)
{
    //use linked-neighbour.
    vector<vector<int> > nb(N,vector<int>());
    for(int i=0;i<edges.size();i++)
    {
        nb[edges[i].first].push_back(edges[i].second);
    }
    //
    vector<bool> visited(N,false);
    return dfs(nb,visited,x,y);
}

int main(){

}

