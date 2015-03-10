#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int (*fun)(int n);
int p3(int n)
{
    return n*(n+1)/2;
}
int p4(int n)
{
    return n*n;
}
int p5(int n)
{
    return n*(3*n-1)/2;
}
int p6(int n)
{
    return n*(2*n-1);
}
int p7(int n)
{
    return n*(5*n-3)/2;
}
int p8(int n)
{
    return n*(3*n-2);
}
vector<int> num[6];
void match(vector<int> &v){
    int n=1;
    int res=1;
    while(res<10000)
    {
	if(res>1000&&res%100>9)
            v.push_back(res);
        n++;
        res=fun(n);
        

    }
}
vector<int> nbr;
bool mp[100]={false};
int indgree[100]={0};
int outdgree[100]={0};
template<int maxn>
struct UnionFind{
    int fa[maxn+1];
    UnionFind(){
        for(int i=0;i<=maxn;i++)
            fa[i]=i;
    }
    void Union(int x,int y)
    {
        int fx=find(x);
        int fy=find(y);
        if(fx!=fy)
        {
            fa[fy]=fx;
        }
    }
    int find(int x)
    {
        if(x!=fa[x])
        {
           x=find(fa[x]);
        }
        return fa[x];
    }
};
template<int maxn>
bool liantong(UnionFind<maxn> &uf,vector<int> &nbr)
{//this is a euler loop ,indgree==outdgree && is liantong graph
    bool msk[100]={false};
    for(int i=0;i<nbr.size();i++)
    {
       msk[uf.find(nbr[i])]=true;
    }
    int cnt=0;
    for(int i=0;i<100;i++)
       if(msk[i])
	  cnt++;
    return cnt==1;
}
void guolv(vector<int> num[6],int i[6])
{
	for(int m=0;m<num[i[0]].size();m++)
	{
	int x=num[i[0]][m]/100;
	int y=num[i[0]][m]%100;
	bool fd=false;
	for(int j=1;j<6;j++)
	{
		if(fd)
			break;
		for(int k=0;k<num[i[j]].size();k++)
		{
			if(y==num[i[j]][k]/100)
			{fd=true;break;}
		}
	}
	if(!fd)
		num[i[0]][m]=0;
	}
}
void doguolv(vector<int> num[6])
{
	int tt=0;    
	
	int id[]={0,1,2,3,4,5};
	guolv(num,id);
	swap(id[0],id[1]);
	guolv(num,id);
	swap(id[0],id[2]);
	guolv(num,id); 
	swap(id[0],id[3]);
	guolv(num,id); 
	swap(id[0],id[4]);
	guolv(num,id); 
	swap(id[0],id[5]);
	guolv(num,id);   
	for(int i=0;i<6;i++){
	for(int j=0;j<num[i].size();j++)
	{
		if(num[i][j]!=0)
		{
		cout<<num[i][j]<<' ';
		tt++;
		}
	}
	cout<<endl;
	}
    cout<<tt<<endl;
}
int main(){
    fun=&p3;
    match(num[0]);
    fun=&p4;
    match(num[1]);
    fun=&p5;
    match(num[2]);
    fun=&p6;
    match(num[3]);
    fun=&p7;
    match(num[4]);
    fun=&p8;
    match(num[5]);
	doguolv(num);
	doguolv(num);
	doguolv(num);
 
	//make graph
    for(int i0=0;i0<num[0].size();i0++)
    for(int i1=0;i0<num[1].size();i1++)
    for(int i2=0;i0<num[2].size();i2++)
    for(int i3=0;i0<num[3].size();i3++)
    for(int i4=0;i0<num[4].size();i4++)
    for(int i5=0;i0<num[5].size();i5++)
    {
        nbr.clear();
        memset(indgree,0,sizeof(indgree));
        memset(outdgree,0,sizeof(outdgree));
        UnionFind<100> uf;
        int x=num[0][i0]/100;
        int y=num[0][i0]%100;
        nbr.push_back(x);
        nbr.push_back(y);
        uf.Union(x,y);
        indgree[y]++;
        outdgree[x]++;
        x=num[1][i1]/100;
        y=num[1][i1]%100;
        nbr.push_back(x);
        nbr.push_back(y);
        uf.Union(x,y);
        indgree[y]++;
        outdgree[x]++;
        x= num[2][i2]/100;
        y =num[2][i2]%100;
	nbr.push_back(x);
        nbr.push_back(y);
        uf.Union(x,y);
        indgree[y]++;
        outdgree[x]++;
        x=num[3][i3]/100;
        y=num[3][i3]%100;
        nbr.push_back(x);
        nbr.push_back(y);
        uf.Union(x,y);
        indgree[y]++;
        outdgree[x]++;
         x=num[4][i4]/100;
         y=num[4][i4]%100;
        nbr.push_back(x);
        nbr.push_back(y);
        uf.Union(x,y);
        indgree[y]++;
        outdgree[x]++;
         x=num[5][i5]/100;
         y=num[5][i5]%100;
        nbr.push_back(x);
        nbr.push_back(y);
        uf.Union(x,y);
        indgree[y]++;
        outdgree[x]++;
        bool candidate=true;
        for(int i=0;i<100;i++)
            if(indgree[i]!=outdgree[i])
            {
                candidate=false;
                break;
            }
        if(!candidate)
            continue;
          
        if(liantong(uf,nbr))
        {
            cout<<num[0][i0]
            <<' '<<num[1][i1]
            <<' '<<num[2][i2]
            <<' '<<num[3][i3]
            <<' '<<num[4][i4]
            <<' '<<num[5][i5]<<endl;
            return 0;
        }

    }
}
