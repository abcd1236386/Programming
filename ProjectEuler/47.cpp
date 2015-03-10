#include<iostream>
#include<set>
#include<vector>
using namespace std;
vector<int> prime;
int primefactors(int num)
{
    set<int> fn;
    for(int i=0;i<prime.size();i++)
    {
        if(prime[i]>num/2)
            break;
        if(num%prime[i]==0)
        {
            fn.insert(prime[i]);
        }
    }
    if(fn.size()==0)
        prime.push_back(num);

    return fn.size();
}
int main(){
    int num=2;
    int con=0;
    int tofind=4;
    cin>>tofind;
    while(1){
        if(primefactors(num)==tofind)
        {
            con++;
            if(con==tofind)
            {
                cout<<num<<endl;
                break;
            }
        }
        else
            con=0;
        num++;
    }

}
