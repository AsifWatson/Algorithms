#include<bits/stdc++.h>
using namespace std;

long long mod;

long long bigMod(long long number,long long power)
{
	if(power==0) return 1;
	if(power%2==0)
	{
		long long ret=bigMod(number,power/2);

		return ((ret%mod)*(ret%mod))%mod;
	}
	else return ((number%mod)*(bigMod(number,power-1)%mod))%mod;
}

int main()
{
    long long Number,power;
    cout<<"Cin Number,Power,Mode"<<endl;
    cin>>Number>>power>>mod;
    cout<<bigMod(Number,power)<<endl;
    return 0;
}
