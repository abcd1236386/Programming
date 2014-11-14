#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace std;
int order[256];
int cost[256]; //the cost
char ch[]={"MfDeCdLcXbVaI"};//13 letters
void minRoman(string cur,string& out,int num,int curidx,int curlen,int &maxlen)
{
    if(num==0&&curlen<=maxlen)// find one
    {    maxlen=curlen;
        out=cur;
        return;
    }
    if(curlen>=maxlen||curidx>=13||num<0)
        return;
    minRoman(cur,out,num,curidx+1,curlen,maxlen);//not use this
    cur.push_back(ch[curidx]);
    minRoman(cur,out,num-order[ch[curidx]],curidx,curlen+cost[ch[curidx]],maxlen);

}
string NumToRoman(int num){
    string ret;
    return ret;
}
int RomanToNum(string str){
    int num=0;
    for(int i=0;i<str.size()-1;i++)
    {
        if(order[str[i]]<order[str[i+1]]){
            num-=order[str[i]];
        }
        else
            num+=order[str[i]];
    }
    num+=order[str[str.size()-1]];
    return num;
}
int romanToInt( std::string s )
{
      int result = 0, pos, i;
        static std::string str[] = {"CM","M","CD","D","XC","C","XL","L","IX","X","IV","V","I"};
          static int val[] = {900,1000,400,500,90,100,40,50,9,10,4,5,1};
            for ( i = 0; i < 13; ++i )
                    while ( (pos = s.find( str[i] )) != std::string::npos )
                            {
                                      result += val[i];
                                            s.erase( pos, str[i].size() );
                                                }
                                                  return result;
}
std::string intToRoman( int i )
{
      static std::string Clist[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        static std::string Xlist[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
          static std::string Ilist[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
            std::string result;
              result.resize( i / 1000, 'M' );
                i %= 1000;
                  result += Clist[ i / 100 ];
                    i %= 100;
                      return result + Xlist[ i / 10 ] + Ilist[ i % 10 ];
}

int main(){
    order['I']=1;
    order['V']=5;
    order['X']=10;
    order['L']=50;
    order['C']=100;
    order['D']=500;
    order['M']=1000;
    //we use a b c d e f present the 4 9 40 90 and 400 900
    order['a']=4;
    order['b']=9;
    order['c']=40;
    order['d']=90;
    order['e']=400;
    order['f']=900;
    
    cost['I']=1;
    cost['V']=1; 
    cost['X']=1;
    cost['L']=1;
    cost['C']=1;
    cost['D']=1;
    cost['M']=1;
    cost['a']=2;
    cost['b']=2;
    cost['c']=2;
    cost['d']=2;
    cost['e']=2;
    cost['f']=2;
    string str;
    int total=0;
    int ototal=0;
    while(cin>>str)
    {
        int num=RomanToNum(str);
       // if(num!=romanToInt(str))
       //     throw "error";
       // cout<<num<<endl;
        int maxlen=str.size();
        ototal+=maxlen;
        string nRom;
        minRoman("",nRom,num,0,0,maxlen);
        //cout<<maxlen<<endl;
       string your=intToRoman(num);
       if(maxlen!=your.size())
           cout<<your<<" "<<nRom<<endl;
        total+=maxlen;
       // if(maxlen<str.size())
        {

        //    cout<<str<<"-->"<<nRom<<endl;
        //cout<<str<<"-->\t"<<nRom<<endl;
        }
    }
    cout<<total<<endl;
    cout<<ototal<<endl;
    
}
