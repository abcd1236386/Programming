/*
ID:haoziyi1
PROG:spin
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
#include<climits>
using namespace std;
ifstream fin("spin.in");
ofstream fout("spin.out");
struct inter{
    int s,e;
    inter(int x=0,int y=0){
        s=x;
        e=y;
    }
    bool operator *(inter & in){
        if(e<360&&in.e<360||e>=360&&in.e>=360)
        return !(in.s>e||in.e<s);
        else //one of it is 
        if(e>=360){
            return !(in.s>e-360);
        }
        else
            return !(s>in.e-360);

    }
    void add(int x){
        s+=x;
        e+=x;
        if(s>=360){
            s-=360;
            e-=360;
        }
    }
	inter gen(inter &in){
		inter ret(max(in.s,s),min(e,in.e));
		if(ret.empty()){
			if(e>=360)
				return inter(max(s-360,in.s),min(e-360,in.e));
			else if(in.e>=360)
				return inter(max(in.s-360,s),min(in.e-360,e));
		}
		return ret;

	}
	bool empty(){
		return s>e;
	}
};
vector<inter> vi[5];
int spd[5];
bool check()
{
    inter in(INT_MIN,INT_MAX);
    inter t;
    for(int i=0;i<vi[0].size();i++){
        for(int j=0;j<vi[1].size();j++){
            in=vi[0][i].gen(vi[1][j]);
			if(in.empty())
                continue;
            for(int k=0;k<vi[2].size();k++){
                t=vi[2][k].gen(in);
                if(t.empty())
					continue;
				in=t;
                for(int l=0;l<vi[3].size();l++){
                    t=in.gen(vi[3][l]);
                    if(t.empty())
						continue;
					in=t;
                    for(int m=0;m<vi[4].size();m++){
                        t=in.gen(vi[4][m]);
						if(t.empty())
							continue;
						in=t;
                        return true;
                    }
                }
            }
        }
    }
    return false;   
}
int main(){
    int n;
    for(int i=0;i<5;i++){
        fin>>spd[i]>>n;
        for(int j=0;j<n;j++){
            inter in;
            fin>>in.s>>in.e;
            in.e+=in.s;
            vi[i].push_back(in);
        }
    }
    //check.
    int t=-1;
    if(check())
        t=0;
    for(int i=0;t==-1&&i<360;i++){
        for(int j=0;j<5;j++)
        {
            for(int k=0;k<vi[j].size();k++){
                vi[j][k].add(spd[j]);
            }
        }
        if(check())
            t=i+1;
    }
    if(t==-1)
        fout<<"none\n";
    else
        fout<<t<<endl;
}

