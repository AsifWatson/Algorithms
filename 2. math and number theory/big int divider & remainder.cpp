#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<string,ll> divideBigNumber(string num, ll divisor)
{
    vector<int> vec;
    ll mod=0;
    string divider="";

    for(int i=0;i<num.size();i++)
    {
        int digit=num[i]-'0';
        mod=mod*10+digit;
        int div=mod/divisor;
        vec.push_back(div);
        mod=mod%divisor;
    }

    bool zeroflag = 0;
    for (int i=0;i<vec.size();i++)
    {
        if(vec[i]==0 && zeroflag==0)continue;
        zeroflag=1;
        divider+=(vec[i]+'0');
    }
    return {divider,mod};
}

int main()
{
    string num="14598448265358544";
    ll divisor=487;
    pair<string,int> p=divideBigNumber(num,divisor);
    cout<<p.first<<" "<<p.second<<endl;
    return 0;
}
