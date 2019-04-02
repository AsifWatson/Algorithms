#include <bits/stdc++.h>
using namespace std;

string longDivision(string number, int divisor)
{
    string ans;

    int idx=0;
    int temp=number[idx]-'0';
    while(temp<divisor)temp=temp*10+(number[++idx]-'0');

    while(number.size()>idx)
    {
        ans+=(temp/divisor)+'0';
        temp=(temp%divisor)*10+number[++idx]-'0';
    }

    if(ans.length()==0)return "0";

    return ans;
}

int main()
{
    string number ="1248163264128256512";
    int divisor=500;
    cout<<longDivision(number,divisor);
    return 0;
}
