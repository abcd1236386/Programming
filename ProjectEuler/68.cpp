#include<iostream>
#include<algorithm>
#include<string>
#include<functional>
using namespace std;

string numtmp[10]={"1","2","3","4","5","6","7","8","9","10"};
struct strnum{
    int num;
    string str;
}num[10];
bool strless(const strnum &s1,const strnum &s2)
{
    return s1.num<s2.num;
}
bool checkvalid(strnum * n,int maxn=10)
{
    // 167 ,278,389,4910,5106
    int i[15]={1,6,7,2,7,8,3,8,9,4,9,10,5,10,6};
    int sum=-1;
    for(int j=0;j<15;j+=3)
    {
        i[j]--;
        i[j+1]--;
        i[j+2]--;
        if(sum==-1)
            sum=n[i[j]].num+n[i[j+1]].num+n[i[j+2]].num;
        else if(sum!=n[i[j]].num+n[i[j+1]].num+n[i[j+2]].num)
            return false;
     }
     return true;
}
string cont(strnum *n)
{
    int mid=0;
    int min=n[0].num;
    int idlist[5][3]={
        {0,5,6},
        {1,6,7},
        {2,7,8},
        {3,8,9},
        {4,9,5}
        };
    for(int i=1;i<5;i++)
        if(n[i].num<n[mid].num)
            mid=i;
    string str;
    for(int i=mid;i<mid+5;i++)
    {
        int j=i%5;
        for(int k=0;k<3;k++)
            str+=num[idlist[j][k]].str;
    }
    return str;
}
int main(){
    int maxn=10;
    for(int i=0;i<maxn;i++)
    {
        num[i].str=numtmp[i];
        num[i].num=i+1;
    }
    string max="";
    do{
        if(checkvalid(num))
        {
            string str=cont(num);
            cout<<str<<endl;
            if(str.size()==16)
            {
                if(max==""||max<str)
                    max=str;
            }
        }
    }
    while(next_permutation(num,num+10,strless));
    cout<<"max is:"<<max<<endl;
}
